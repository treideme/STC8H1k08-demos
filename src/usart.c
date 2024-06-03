#include "hardware.h"
#include "usart.h"

char busy;
char wptr;
char rptr;
char buffer[16];

void usart0_init() {
  SCON = CONF_SCON0;
  TMOD = 0x00;
  TL1 = BRT & 0xFF;
  TH1 = BRT >> 8;
  TR1 = 1;
  wptr = 0x00;
  rptr = 0x00;
  busy = 0;
  ES = 1;
}

void usart0_send(char dat) {
  while(busy);
  busy = 1;
  SBUF = dat;
}

void usart0_send_str(char *dat) {
  while(*dat) {
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
    buffer[wptr++] = SBUF;
    wptr &= 0x0f;
  }
}
