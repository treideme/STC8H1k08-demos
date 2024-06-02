#include "hardware.h"
#include "usart.h"

static volatile unsigned char busy;

void usart0_init() {
  // UART configuration
  PCON &= ~0b01000000; // Set SMOD0 to 0
  SCON = CONF_SCON0;
  // USE T1 mode 0 for baud rate generation
  TMOD = 0x20;
  SCON = 0x50;
  TMOD = 0x00;
  TL1 = BRT & 0xFF;
  TH1 = BRT >> 8;
  TR1 = 1;
  AUXR = 0x40;
  busy = 0;
}

void usart0_send(char dat) {
  while (busy);
  busy = 1;
  SBUF = dat;
}

void usart0_send_str(char *dat) {
  while(dat) {
    usart0_send(*dat++);
  }
}

// USART0 Interrupt service routine
void usart0_isr() __interrupt (SI0_VECTOR) {
  if (TI) {
    TI = 0;
    busy = 0;
  }

  if (RI) {
    RI = 0;
  }
}
