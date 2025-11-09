# Silicon Labs ZigBee firmware builder repository

> [!IMPORTANT]
> Builds here are updated fairly fast after new changes/releases, hence, you can consider them somewhat similar to the difference between Zigbee2MQTT "normal" branch, and dev/edge branch.

This repository contains building tools and firmware releases for the most common ZigBee adapters.

It uses the Silicon Labs Simplicity SDK and proprietary Silicon Labs tools such as the Silicon Labs Configurator (slc) and the Simplicity Commander standalone utility.

## Flashing

See https://www.zigbee2mqtt.io/guide/adapters/emberznet.html#firmware-flashing

## Choosing the right firmware

### Filename convention

`<brand>_<model>_<firmware-type>_<version>_<baudrate>_<flow-control>.gbl`

`<model>` may include a more specific configuration, e.g. `<model>-noled` for router builds that disable the LEDs.

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
