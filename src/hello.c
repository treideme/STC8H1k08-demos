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
 * @file hello.c Hello World project for the STC8H1K08 chip.
 * @author Thomas Reidemeister
 */
#include "hardware.h"

static void delay(unsigned int t);

void main() {
  hardware_init();
  // Set all P1 pins as push-pull outputs
  P1M0 = 0x04; // Set P1.2 as push-pull output
  P1M1 = 0xFB;  // Clear all bits of P1M1, except P1_2
  WKTCL = 0xFE; // Set the power-down wake-up clock to be about 10 seconds
  WKTCH = 0xFF;

  delay(0xfff); // Wait a bit so we can reflash the chip

  P3M0 = 0x00; // Set P1.2 as push-pull output
  P3M1 = 0xFF; // Clear all bits of P1M1, except P1_2

  P5M0 = 0x00; // Set P1.2 as push-pull output
  P5M1 = 0xFF; // Clear all bits of P1M1, except P1_2

  P1_2 = 1;

  while (1) {
    P1_2 = 0x1;  // Toggle P1.2
    delay(0xffff);
    P1_2 = 0x0;
    PCON |= 0x02;  // Enter power-down mode
    delay(0xffff);
  }
}

static void delay(unsigned int t) {
  while (t--) {
    volatile int i = 100;
    while (i--);
  }
}

