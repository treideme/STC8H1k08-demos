/**
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * @file hardware.h
 * @brief Project hardware configuration
 * @author Thomas Reidemeister
 *
 *                                      +----------+
 *                   T2/SS/PWM2P/P1.2 --+ 1     20 +-- P1.1/ADC1/TxD2/PWM1N
 *             T2CLKO/MOSI/PWM2N/P1.3 --+ 2     19 +-- P1.0/ADC0/RxD2/PWM1P
 *             I2CSDA/MISO/PWM3P/P1.4 --+ 3     18 +-- P3.7/INT3/TxD_2/CMP+
 *             I2CSCL/SCLK/PWM3N/P1.5 --+ 4     17 +-- P3.6/ADC14/INT2/RxD_2/CMP-
 *     XTAL0/MCLKO_2/RxD_3/PWM4P/P1.6 --+ 5     16 +-- P3.5/ADC13/T1/T0CLKO/SS_4/PWMFLT/PWMFLT2
 *      XTAL1/TxD_3/PWM5_2/PWM4N/P1.7 --+ 6     15 +-- P3.4/ADC12/T0/T1CLKO/MOSI_4/PWM4P_2/PWM8_2/CMPO
 *              MCLKO/RST/PWM6_2/P5.4 --+ 7     14 +-- P3.3/ADC11/INT1/MISO_4/I2CSDA_4/PWM4N_2/PWM7_2
 *                           Vcc/AVcc --+ 8     13 +-- P3.2/ADC10/INT0/SCLK_4/I2CSCL_4/PWMETI/PWMETI2
 *                          ADC_VRef+ --+ 9     12 +-- P3.1/ADC9/TxD
 *                           Gnd/AGnd --+ 10    11 +-- P3.0/ADC8/RxD/INT4
 *                                      +----------+
 *
 */
#ifndef HARDWARE_H
#define HARDWARE_H

#include "stc8h.h"

#define __CONF_CLKDIV 0x00

void hardware_init();

#endif // HARDWARE_H
