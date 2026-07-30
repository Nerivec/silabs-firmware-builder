# Silicon Labs ZigBee firmware builder repository

> [!IMPORTANT]
> `Pre-release` builds are updated fairly fast after new SDK releases.
> `Latest` builds usually come after a `Pre-release` has been available for a while and no issue is pending.
>
> Builds also purposely focus on the main needs of each firmware type (no unnecessary extras).

> [!TIP]
> [Starting with SDK v2026.6.0](https://docs.silabs.com/sisdk-release-notes/2026.6.0/sisdk-release-notes-overview/#release-announcement), Silabs is considering June releases (`vyyyy.6.p`) as LTS ("recommended baseline for production" - 30-month maintenance), and December releases (`vyyyy.12.p`) as Interim ("for prototyping, early feature access, and development work" - 6-month maintenance).

This repository contains building tools and firmware releases for the most common Zigbee and OpenThread Silabs adapters.

It uses the Silicon Labs Simplicity SDK and proprietary Silicon Labs tools such as the Silicon Labs Configurator (slc) and the Simplicity Commander standalone utility.
https://docs.silabs.com/sisdk-release-notes/2026.6.1/sisdk-release-notes-overview/

## Flashing

See https://www.zigbee2mqtt.io/guide/adapters/emberznet.html#firmware-flashing

## Choosing the right firmware

### Filename convention

`<brand>_<model>_<firmware-type>_<sdk-version>_<version>_<baudrate>_<flow-control>.gbl`

`<model>` may include a more specific configuration (see below).

#### Model - special cases

- `<model>-noled` => builds that disable the LEDs
- `slzb06mu` => use `slzb06m`
- `slzb06Mg24u` => use `slzb06Mg24`
- `slzbmr1u` => use `slzb06m`
- `slzbmr2u` => use `slzb06m`
- `slzbmr3u` => use `slzb06Mg26u`
- `slzbmr4u` => use `slzb06Mg26`
- `slzbmr5u` => use `slzb06Mg24`

#### Baudrate

The baudrate your firmware is configured to work with MUST BE configured identically in the application you will use (e.g. Zigbee2MQTT).

> [!IMPORTANT]
> For TCP-based adapters, changing the firmware baudrate will usually require changing the baudrate of the base board (e.g. the ESP/core side) to match.

> [!TIP]
> Silabs uses 115200 baudrate for bootloader. This baudrate is independent of the application firmware baudrate. Most flashers will automatically use 115200 when entering the bootloader, independently of the application baudrate you may have set.

#### Flow control

- `sw_flow`: software flow control
  - Usually the default in most applications, `rtscts: false`
- `hw_flow`: hardware flow control
  - Usually requires explicitly being set, `rtscts: true`

### Zigbee NCP

> [!TIP]
> `NCP`: Network Co-Processor

The typical firmware for use with Zigbee networks. The adapter runs as a coordinator in conjunction with e.g. Zigbee2MQTT.

See https://www.zigbee2mqtt.io/guide/adapters/emberznet.html

### Zigbee Router

Turns an adapter into a dedicated router. Its sole purpose will be to route traffic in your network. If properly physically placed, it can greatly enhance the stability of your network. _You can have more than one of these in your network._

> [!TIP]
> For future updates or firmware changes, Zigbee2MQTT will allow you to enter the bootloader from the frontend/MQTT, which should make things easier for adapters without a bootloader button (no need to open it up). Just trigger the reset, then start the flasher (should detect the bootloader automatically).

### OpenThread RCP

> [!TIP]
> `RCP`: Radio Co-Processor (see https://openthread.io/platforms/co-processor#radio_co-processor_rcp)

The adapter runs as a minimal layer over the radio and leaves the rest to be handled by the host (e.g. OpenThread Border Router).

This kind of firmware can technically be used for any 802.15.4 network thanks to the more "direct" access to the radio. It is for example used in the [Zigbee on Host](https://github.com/Nerivec/zigbee-on-host) project.

It is [Open Source](https://github.com/openthread).

### Bootloader

The bootloader serves as a base for handling the application firmware (flashing, running, etc.). Updating this is rarely _required_, as most updates are about adding support for new chips, though you can keep it up to date just like a regular firmware.

> [!TIP]
> With Silabs hardware, as long as the bootloader remains operational, you can usually recover from any kind of application firmware trouble (although it may require opening the case and manually triggering said bootloader). See https://github.com/Nerivec/silabs-firmware-recovery

## Customizing firmware builds (forks)

Beware:
- This builder uses the yaml `name` property to define some in-firmware constants. These are required for proper recognition in certain circumstances (e.g. Z2M support for `zigbee_router`).
- Pins & flow control should be set carefully according to the board. The firmware just won't work otherwise.
- Increasing a config results in more memory allocated (varies based on the config). If too much memory is allocated for a board, the building of the firmware _should_ fail.
- Use of `FF` for configs (e.g. `0xFF` -`255`- for uint8). These usually have special meaning and may have unintended consequences. Best to use 254 if wanting "max", else verify the actual stack config once flashed: https://github.com/Nerivec/ember-zli/wiki/Stack#get-stack-config-firmware-defaults
- Some tables may not have any use (or very limited) in specific contexts (e.g. `zigbee_ncp` vs `zigbee_router`, group-heavy network, etc.), hence, changing sizes could result in wasted memory in that area.


https://docs.silabs.com/zigbee/latest/sisdk-ezsp-reference-guide/

https://docs.silabs.com/zigbee/latest/sisdk-ezsp-reference-guide/02-emberznet-serial-protocol#configuration-values
