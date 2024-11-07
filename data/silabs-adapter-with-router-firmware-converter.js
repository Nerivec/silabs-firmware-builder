const {linkQuality} = require('zigbee-herdsman-converters/lib/modernExtend');
const {factory_reset} = require('zigbee-herdsman-converters/converters/toZigbee');
const {presets, access} = require('zigbee-herdsman-converters/lib/exposes');

const definitions = {
    fingerprint: [
        {modelID: 'ZGA008', manufacturerName: 'Aeotec'},
        {modelID: 'ZB-GW04', manufacturerName: 'easyiot'},
        {modelID: 'ZB-GW04-1v1', manufacturerName: 'easyiot'},
        {modelID: 'ZB-GW04-1v2', manufacturerName: 'easyiot'},
        {modelID: 'SkyConnect', manufacturerName: 'NabuCasa'},
        {modelID: 'SLZB-06M', manufacturerName: 'SMLIGHT'},
        {modelID: 'SLZB-07', manufacturerName: 'SMLIGHT'},
        {modelID: 'SLZB-07MG24', manufacturerName: 'SMLIGHT'},
        {modelID: 'DONGLE-E', manufacturerName: 'SONOFF'},
        {modelID: 'MGM240P', manufacturerName: 'SparkFun'},
        {modelID: 'MGM24', manufacturerName: 'TubesZB'},
        {modelID: 'MGM24PB', manufacturerName: 'TubesZB'},
    ],
    model: 'Silabs series 2 router',
    vendor: 'Silabs',
    description: 'Silabs series 2 adapter with router firmware',
    toZigbee: [factory_reset],
    exposes: [
        presets
            .enum('reset', access.SET, ['reset'])
            .withDescription('Resets and launches the bootloader for flashing. If USB, ensure the device is already connected to the machine where you intend to flash it before triggering this.'),
    ],
    extend: [linkQuality({reporting: true})],
    meta: {disableDefaultResponse: true},
};

module.exports = definitions;
