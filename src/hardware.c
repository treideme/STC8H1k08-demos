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
 * @file hardware.c Common Routines for Hardware Configuration.
 * @author Thomas Reidemeister
 */
#include "hardware.h"

void hardware_init(void) {
  SFRX_ON();
  int i = 5;
  if (CLKDIV != (__CONF_CLKDIV)) {
    CLKDIV = (__CONF_CLKDIV);
    while (--i); // Wait a while after clock changed, or it may block the main process
  }
  SFRX_OFF();
}