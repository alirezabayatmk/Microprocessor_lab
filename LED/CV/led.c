/*******************************************************
This program was created by the
CodeWizardAVR V3.12 Advanced
Automatic Program Generator
© Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 1/24/2021
Author  : 
Company : 
Comments: 


Chip type               : ATmega16
Program type            : Application
AVR Core Clock frequency: 12.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 256
*******************************************************/

#include <mega16.h>
#include <delay.h>

void main(void) {
    int led_st = 0;
    DDRB = 0xff;

    while (1) {
        if (PINA.0 == 1)
        {
            led_st = 1;
            while (led_st <= 0xff) {
                PORTB = led_st;
                delay_ms(100);
                led_st <<= 1;
            }
            led_st = 0;
            while (led_st >= 0x1) {
                PORTB = led_st;
                delay_ms(100);
                led_st >>= 1;
            }
        } else {
            PORTB = 0;
            led_st = 0;
        }
    }
}