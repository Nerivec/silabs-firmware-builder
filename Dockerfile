# Python virtual environment for the firmware builder script
FROM debian:trixie-slim AS python-venv
COPY --from=ghcr.io/astral-sh/uv:latest /uv /uvx /usr/bin/
COPY requirements.txt /tmp/
RUN UV_PYTHON_INSTALL_DIR=/opt/pythons uv venv -p 3.14 /opt/venv --no-cache \
    && uv pip install --python /opt/venv -r /tmp/requirements.txt

# Install slt and all toolchain packages
FROM debian:trixie-slim AS slt-toolchain
ARG TARGETARCH

# Set up slt and conan
RUN set -e \
    && apt-get update && apt-get install -y --no-install-recommends \
        aria2 \
        ca-certificates \
        # Required by conan
        libarchive-tools \
        bzip2 \
        unzip \
    && rm -rf /var/lib/apt/lists/* \
    && aria2c --checksum=sha-256=8c2dd5091c15d5dd7b8fc978a512c49d9b9c5da83d4d0b820cfe983b38ef3612 -o slt.zip \
        https://www.silabs.com/documents/public/software/slt-cli-1.1.0-linux-x64.zip \
    && bsdtar -xf slt.zip -C /usr/bin && rm slt.zip \
    && chmod +x /usr/bin/slt \
    && slt --non-interactive install conan

# Install toolchain via slt
RUN set -e \
    && apt-get update && apt-get install -y --no-install-recommends jq && rm -rf /var/lib/apt/lists/* \
    # https://updates.silabs.com/studio/v6/updates/update_site/manifest.zip
    && slt --non-interactive install \
        cmake/3.30.2 \
        ninja/1.12.1 \
        commander/1.24.1 \
        slc-cli/6.0.22 \
        simplicity-sdk/2026.6.0 \
        zap/2026.06.17 \
    # Unused, remove to save space
    && slt --non-interactive uninstall --force llvm-arm-toolchain-for-embedded \
    # Clean up download caches to reduce image size
    && rm -rf /root/.silabs/slt/installs/archive/*.zip \
              /root/.silabs/slt/installs/archive/*.tar.* \
              /root/.silabs/slt/installs/conan/p/*/d/ \
              /root/.silabs/slt/installs/conan/download_cache \
    # Create stable symlinks and wrappers to make the tools available in PATH
    && mkdir -p /root/.silabs/slt/bin \
    && ln -s "$(slt where java21)/jre/bin/java" /root/.silabs/slt/bin/java \
    && ln -s "$(slt where commander)/commander" /root/.silabs/slt/bin/commander \
    && ln -s "$(slt where cmake)/bin/cmake" /root/.silabs/slt/bin/cmake \
    && ln -s "$(slt where ninja)/ninja" /root/.silabs/slt/bin/ninja \
    # slc needs a wrapper script because it uses $(dirname "$0") to find slc.jar
    && printf '#!/bin/sh\nexec "%s/slc" "$@"\n' "$(slt where slc-cli)" > /root/.silabs/slt/bin/slc \
    && chmod +x /root/.silabs/slt/bin/slc

# Final image
FROM debian:trixie-slim
ARG TARGETARCH

ENV LANG=C.UTF-8
ENV LC_ALL=C.UTF-8

# Install only runtime packages
RUN set -e \
    && apt-get update \
    && apt-get install -y --no-install-recommends \
       ca-certificates \
       git \
       jq \
       libstdc++6 \
       libgl1 \
       libpng16-16 \
       libpcre2-16-0 \
       libglib2.0-0 \
    && rm -rf /var/lib/apt/lists/* \
    # Fix git permission error when building locally
    && git config --global --add safe.directory '*'

# Copy from parallel stages
COPY --from=python-venv /opt/pythons /opt/pythons
COPY --from=python-venv /opt/venv /opt/venv
COPY --from=slt-toolchain /usr/bin/slt* /usr/bin/
COPY --from=slt-toolchain /root/.silabs /root/.silabs

# Signal to the firmware builder script that we are running within Docker
ENV SILABS_FIRMWARE_BUILD_CONTAINER=1
ENV HOME=/root
ENV PATH="$PATH:/root/.silabs/slt/bin"

WORKDIR /repo

ENTRYPOINT ["/opt/venv/bin/python3", "tools/build_project.py"]