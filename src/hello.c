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
 * @file hello.c Hello World project for the STC89C52 chip.
 * @author Thomas Reidemeister
 */
#include <mcs51/8051.h>

// Define SFRs for port mode registers
__sfr __at (0x91) P1M1;
__sfr __at (0x92) P1M0;
//__sfr16 __at (0xFE11) P1PU;  // Port 1 Pull-up Resistor Control Register
//__sfr16 __at (0xFE21) P1SR;  // Port 1 Slew Rate Control Register
//__sfr16 __at (0xFE29) P1DR;  // Port 1 Drive Current Control Register

static void delay(unsigned int t);

void main() {
// Set all P1 pins as push-pull outputs
    P1M0 = 0xFF;  // Set all bits of P1M0
    P1M1 = 0x00;  // Clear all bits of P1M1

    // Disable pull-up resistors for all P1 pins
  //  P1PU = 0x00;

    // Set drive current to high for all P1 pins
    //P1DR = 0xFF;

    // Enable fast slew rate for all P1 pins
//    P1SR = 0xFF;

    while (1) {
        P1 = 0xFF;  // Set all P1 pins high, turn the LEDs on
        delay(50000); // Delay
        P1 = 0x00;  // Set all P1 pins low, turn the LEDs off
        delay(50000); // Delay
    }
}


static void delay(unsigned int t) {
  while (t--)
    ;
}
