/*
 *
 *    Copyright (c) 2020-2022 Project CHIP Authors
 *    Copyright (c) 2020 Google LLC.
 *    All rights reserved.
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

/**
 *    @file
 *          Platform-specific configuration overrides for the chip Device Layer
 *          on NXP platforms using the NXP SDK.
 */

#pragma once

// ==================== Platform Adaptations ====================

#ifdef CONFIG_CHIP_USE_GENERATED_CONFIG
#define CHIP_DEVICE_CONFIG_DEVICE_VENDOR_ID CONFIG_CHIP_DEVICE_VENDOR_ID
#define CHIP_DEVICE_CONFIG_DEVICE_VENDOR_NAME CONFIG_CHIP_DEVICE_VENDOR_NAME
#define CHIP_DEVICE_CONFIG_DEVICE_PRODUCT_ID CONFIG_CHIP_DEVICE_PRODUCT_ID
#define CHIP_DEVICE_CONFIG_DEVICE_PRODUCT_NAME CONFIG_CHIP_DEVICE_PRODUCT_NAME
#define CHIP_DEVICE_CONFIG_DEVICE_HARDWARE_VERSION CONFIG_CHIP_DEVICE_HARDWARE_VERSION
#define CHIP_DEVICE_CONFIG_DEFAULT_DEVICE_HARDWARE_VERSION_STRING CONFIG_CHIP_DEVICE_HARDWARE_VERSION_STRING
#define CHIP_DEVICE_CONFIG_DEVICE_SOFTWARE_VERSION CONFIG_CHIP_DEVICE_SOFTWARE_VERSION
#define CHIP_DEVICE_CONFIG_DEVICE_SOFTWARE_VERSION_STRING CONFIG_CHIP_DEVICE_SOFTWARE_VERSION_STRING
#define CHIP_DEVICE_CONFIG_TEST_MANUFACTURING_DATE CONFIG_CHIP_DEVICE_MANUFACTURING_DATE
#define CHIP_DEVICE_CONFIG_DEVICE_TYPE CONFIG_CHIP_DEVICE_TYPE

#if !CONFIG_CHIP_PLAT_LOAD_REAL_FACTORY_DATA
#define CHIP_DEVICE_CONFIG_USE_TEST_SETUP_DISCRIMINATOR CONFIG_CHIP_DEVICE_DISCRIMINATOR
#define CHIP_DEVICE_CONFIG_USE_TEST_SETUP_PIN_CODE CONFIG_CHIP_DEVICE_SPAKE2_PASSCODE
#define CHIP_DEVICE_CONFIG_USE_TEST_PAIRING_CODE CONFIG_CHIP_DEVICE_USE_TEST_PAIRING_CODE
#define CHIP_DEVICE_CONFIG_TEST_SERIAL_NUMBER CONFIG_CHIP_DEVICE_SERIAL_NUMBER
#endif // CONFIG_CHIP_PLAT_LOAD_REAL_FACTORY_DATA

#ifdef CONFIG_CHIP_ENABLE_PAIRING_AUTOSTART
#define CHIP_DEVICE_CONFIG_ENABLE_PAIRING_AUTOSTART CONFIG_CHIP_ENABLE_PAIRING_AUTOSTART
#else
#define CHIP_DEVICE_CONFIG_ENABLE_PAIRING_AUTOSTART 0
#endif

#endif // CONFIG_CHIP_USE_GENERATED_CONFIG

#ifndef CHIP_DEVICE_CONFIG_ENABLE_WIFI_STATION
#if CONFIG_CHIP_WIFI || CHIP_DEVICE_CONFIG_ENABLE_WPA
#define CHIP_DEVICE_CONFIG_ENABLE_WIFI_STATION 1
#else
#define CHIP_DEVICE_CONFIG_ENABLE_WIFI_STATION 0
#endif // CONFIG_CHIP_WIFI || CHIP_DEVICE_CONFIG_ENABLE_WPA
#endif // CHIP_DEVICE_CONFIG_ENABLE_WIFI_STATION

#ifndef CHIP_DEVICE_CONFIG_ENABLE_WIFI_AP
#define CHIP_DEVICE_CONFIG_ENABLE_WIFI_AP 0
#endif // CHIP_DEVICE_CONFIG_ENABLE_WIFI_AP

#ifndef CHIP_DEVICE_CONFIG_ENABLE_THREAD
#ifdef CONFIG_NET_L2_OPENTHREAD
#define CHIP_DEVICE_CONFIG_ENABLE_THREAD CONFIG_NET_L2_OPENTHREAD
#else
#define CHIP_DEVICE_CONFIG_ENABLE_THREAD 0
#endif // CONFIG_NET_L2_OPENTHREAD
#endif // CHIP_DEVICE_CONFIG_ENABLE_THREAD

#if !CHIP_DEVICE_CONFIG_ENABLE_THREAD
#define CHIP_DEVICE_CONFIG_ENABLE_UNPROVISIONED_MDNS 1
#endif // CHIP_DEVICE_CONFIG_ENABLE_THREAD

#ifndef CHIP_DEVICE_CONFIG_ENABLE_CHIPOBLE
#define CHIP_DEVICE_CONFIG_ENABLE_CHIPOBLE 0
#endif // CHIP_DEVICE_CONFIG_ENABLE_CHIPOBLE

#ifndef CHIP_DEVICE_BLE_ADVERTISING_PRIORITY
/// Priority of the Matter BLE advertising when there are multiple application
/// components that compete for the BLE advertising.
/// Increase priority to 1 to allow user to insert custom advertising data with higher priority (0)
#define CHIP_DEVICE_BLE_ADVERTISING_PRIORITY 1
#endif // CHIP_DEVICE_BLE_ADVERTISING_PRIORITY

// ========== Platform-specific Configuration =========

// These are configuration options that are unique to the NXP platform.
// These can be overridden by the application as needed.

/**
 * @def CHIP_DEVICE_LAYER_OTA_REBOOT_DELAY
 *
 * The delay before rebooting after an OTA process was finished.
 */
#ifndef CHIP_DEVICE_LAYER_OTA_REBOOT_DELAY
#define CHIP_DEVICE_LAYER_OTA_REBOOT_DELAY 3000
#endif // CHIP_DEVICE_LAYER_OTA_REBOOT_DELAY

/**
 * @def CONFIG_CHIP_OTA_FACTORY_DATA_PROCESSOR
 *
 * Enables default OTA TLV factory data processor.
 * Disabled by default.
 */
#ifndef CONFIG_CHIP_OTA_FACTORY_DATA_PROCESSOR
#define CONFIG_CHIP_OTA_FACTORY_DATA_PROCESSOR 0
#endif // CONFIG_CHIP_OTA_FACTORY_DATA_PROCESSOR

// ========== Platform-specific Configuration Overrides =========
#ifndef CHIP_DEVICE_CONFIG_CHIP_TASK_STACK_SIZE
#define CHIP_DEVICE_CONFIG_CHIP_TASK_STACK_SIZE 10240
#endif // CHIP_DEVICE_CONFIG_CHIP_TASK_STACK_SIZE

#ifndef CHIP_DEVICE_CONFIG_THREAD_TASK_STACK_SIZE
#define CHIP_DEVICE_CONFIG_THREAD_TASK_STACK_SIZE 8192
#endif // CHIP_DEVICE_CONFIG_THREAD_TASK_STACK_SIZE

#ifndef CHIP_DEVICE_CONFIG_THREAD_TASK_PRIORITY
/* If supported, the Thread task should have a highter priority than the app task */
#define CHIP_DEVICE_CONFIG_THREAD_TASK_PRIORITY 5
#endif // CHIP_DEVICE_CONFIG_THREAD_TASK_PRIORITY

#ifndef CHIP_DEVICE_CONFIG_BLE_APP_TASK_NAME
#define CHIP_DEVICE_CONFIG_BLE_APP_TASK_NAME "BLE App Task"
#endif // CHIP_DEVICE_CONFIG_BLE_APP_TASK_NAME

#ifndef CHIP_DEVICE_CONFIG_ENABLE_WIFI_TELEMETRY
#define CHIP_DEVICE_CONFIG_ENABLE_WIFI_TELEMETRY 0
#endif // CHIP_DEVICE_CONFIG_ENABLE_WIFI_TELEMETRY

#ifndef CHIP_DEVICE_CONFIG_ENABLE_THREAD_TELEMETRY
#define CHIP_DEVICE_CONFIG_ENABLE_THREAD_TELEMETRY 0
#endif // CHIP_DEVICE_CONFIG_ENABLE_THREAD_TELEMETRY

#ifndef CHIP_DEVICE_CONFIG_ENABLE_THREAD_TELEMETRY_FULL
#define CHIP_DEVICE_CONFIG_ENABLE_THREAD_TELEMETRY_FULL 0
#endif // CHIP_DEVICE_CONFIG_ENABLE_THREAD_TELEMETRY_FULL

#ifndef CHIP_DEVICE_CONFIG_CHIPOBLE_DISABLE_ADVERTISING_WHEN_PROVISIONED
#define CHIP_DEVICE_CONFIG_CHIPOBLE_DISABLE_ADVERTISING_WHEN_PROVISIONED 1
#endif // CHIP_DEVICE_CONFIG_CHIPOBLE_DISABLE_ADVERTISING_WHEN_PROVISIONED

#ifndef CHIP_DEVICE_CONFIG_CHIPOBLE_ENABLE_ADVERTISING_AUTOSTART
#define CHIP_DEVICE_CONFIG_CHIPOBLE_ENABLE_ADVERTISING_AUTOSTART 0
#endif // CHIP_DEVICE_CONFIG_CHIPOBLE_ENABLE_ADVERTISING_AUTOSTART

#if CHIP_DEVICE_CONFIG_ENABLE_THREAD
#define CHIP_DEVICE_CONFIG_ENABLE_THREAD_SRP_CLIENT 1
/* Thread DNS client enablement required for OTA */
#define CHIP_DEVICE_CONFIG_ENABLE_THREAD_DNS_CLIENT 1
#endif // CHIP_DEVICE_CONFIG_ENABLE_THREAD

#ifndef CHIP_DEVICE_CONFIG_KVS_WEAR_STATS_KEY
#define CHIP_DEVICE_CONFIG_KVS_WEAR_STATS_KEY "nxp/diag/usr"
#endif // CHIP_DEVICE_CONFIG_KVS_WEAR_STATS_KEY

#if CHIP_DEVICE_CONFIG_ENABLE_THREAD && !CHIP_DEVICE_CONFIG_ENABLE_CHIPOBLE
#define CHIP_DEVICE_CONFIG_ENABLE_COMMISSIONABLE_DISCOVERY 1
#define CHIP_DEVICE_CONFIG_ENABLE_EXTENDED_DISCOVERY 1
#endif

#ifndef CHIP_DEVICE_CONFIG_USE_ZEPHYR_BLE
#define CHIP_DEVICE_CONFIG_USE_ZEPHYR_BLE 1
#endif // CHIP_DEVICE_CONFIG_USE_ZEPHYR_BLE

#ifndef CHIP_DEVICE_CONFIG_PROCESS_BLE_IN_THREAD
#define CHIP_DEVICE_CONFIG_PROCESS_BLE_IN_THREAD 0
#endif // CHIP_DEVICE_CONFIG_PROCESS_BLE_IN_THREAD

#ifndef CHIP_DEVICE_CONFIG_INIT_OT_PLAT_ALARM
#define CHIP_DEVICE_CONFIG_INIT_OT_PLAT_ALARM 1
#endif // CHIP_DEVICE_CONFIG_INIT_OT_PLAT_ALARM

#ifndef CHIP_DEVICE_CONFIG_WIFI_STATION_RECONNECT_INTERVAL
#define CHIP_DEVICE_CONFIG_WIFI_STATION_RECONNECT_INTERVAL 300
#endif // CHIP_DEVICE_CONFIG_WIFI_STATION_RECONNECT_INTERVAL in Milliseconds
