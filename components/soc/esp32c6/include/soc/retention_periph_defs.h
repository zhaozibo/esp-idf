/*
 * SPDX-FileCopyrightText: 2024 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#include <stdint.h>
#include "soc_caps.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum periph_retention_module {
    SLEEP_RETENTION_MODULE_MIN          = 0,
    /* clock module, which includes system and modem */
    SLEEP_RETENTION_MODULE_CLOCK_SYSTEM = 1,
    SLEEP_RETENTION_MODULE_CLOCK_MODEM  = 2,
    /* digital peripheral module, which includes Interrupt Matrix, HP_SYSTEM,
     * TEE, APM, UART, IOMUX, SPIMEM, SysTimer, etc.. */
    SLEEP_RETENTION_MODULE_SYS_PERIPH   = 3,
    /* Timer Group by target*/
    SLEEP_RETENTION_MODULE_TG0_WDT      = 4,
    SLEEP_RETENTION_MODULE_TG1_WDT      = 5,
    SLEEP_RETENTION_MODULE_TG0_TIMER0   = 6,
    SLEEP_RETENTION_MODULE_TG1_TIMER0   = 7,
    /* GDMA by channel */
    SLEEP_RETENTION_MODULE_GDMA_CH0     = 8,
    SLEEP_RETENTION_MODULE_GDMA_CH1     = 9,
    SLEEP_RETENTION_MODULE_GDMA_CH2     = 10,
    /* MISC Peripherals */
    SLEEP_RETENTION_MODULE_ADC          = 11,
    SLEEP_RETENTION_MODULE_I2C0         = 12,
    SLEEP_RETENTION_MODULE_RMT0         = 13,
    SLEEP_RETENTION_MODULE_UART0        = 14,
    SLEEP_RETENTION_MODULE_UART1        = 15,

    /* Modem module, which includes WiFi, BLE and 802.15.4 */
    SLEEP_RETENTION_MODULE_WIFI_MAC     = 26,
    SLEEP_RETENTION_MODULE_WIFI_BB      = 27,
    SLEEP_RETENTION_MODULE_BLE_MAC      = 28,
    SLEEP_RETENTION_MODULE_BT_BB        = 29,
    SLEEP_RETENTION_MODULE_802154_MAC   = 30,

    SLEEP_RETENTION_MODULE_MAX          = SOC_PM_RETENTION_MODULE_NUM - 1
} periph_retention_module_t;

#define is_top_domain_module(m)                           \
    ( ((m) == SLEEP_RETENTION_MODULE_CLOCK_SYSTEM) ? true \
    : ((m) == SLEEP_RETENTION_MODULE_SYS_PERIPH)   ? true \
    : ((m) == SLEEP_RETENTION_MODULE_TG0_WDT)      ? true \
    : ((m) == SLEEP_RETENTION_MODULE_TG1_WDT)      ? true \
    : ((m) == SLEEP_RETENTION_MODULE_TG0_TIMER0)   ? true \
    : ((m) == SLEEP_RETENTION_MODULE_TG1_TIMER0)   ? true \
    : ((m) == SLEEP_RETENTION_MODULE_GDMA_CH0)     ? true \
    : ((m) == SLEEP_RETENTION_MODULE_GDMA_CH1)     ? true \
    : ((m) == SLEEP_RETENTION_MODULE_GDMA_CH2)     ? true \
    : ((m) == SLEEP_RETENTION_MODULE_ADC)          ? true \
    : ((m) == SLEEP_RETENTION_MODULE_I2C0)         ? true \
    : ((m) == SLEEP_RETENTION_MODULE_RMT0)         ? true \
    : ((m) == SLEEP_RETENTION_MODULE_UART0)        ? true \
    : ((m) == SLEEP_RETENTION_MODULE_UART1)        ? true \
    : false)

#ifdef __cplusplus
}
#endif
