/*******************************************************
This program was created by the
CodeWizardAVR V3.12 Advanced
Automatic Program Generator
� Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
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
#include <math.h>

int num = 0;


int container;
int t0 = 0;
int t1 = 0;
int turn = 0;


interrupt [TIM0_OVF]

void timer0_ovf_isr(void) {
    t1++;

    if (t1 == 2) {
        PORTC = pow(2, turn - 1);
        container = num / pow(10, turn - 1);
        container = container % 10;
        PORTD = container;
        turn++;
        if (turn > 4) {
            turn = 1;
        }
        t1 = 0;
    }

    TCNT0 = 0x00;
}


interrupt [TIM1_OVF]

void timer1_ovf_isr(void) {
    t0++;
    if (t0 == 250) {
        if (num > 9999) {
            num = 0;
        }
        num++;
        t0 = 0;
    }

    TCNT1H = 0xFF;
    TCNT1L = 0xF0;
}

void main(void) {
    DDRD = 0xff;
    PORTD = 0xff;

    DDRC = 0xff;
    PORTC = 0xff;

    TIMSK = (0 << OCIE2) | (0 << TOIE2) | (0 << TICIE1) | (0 << OCIE1A) | (0 << OCIE1B) | (1 << TOIE1) | (0 << OCIE0) |
            (1 << TOIE0);

    TCCR0 = (0 << WGM00) | (0 << COM01) | (0 << COM00) | (0 << WGM01) | (1 << CS02) | (0 << CS01) | (1 << CS00);
    TCCR1B = (0 << ICNC1) | (0 << ICES1) | (0 << WGM13) | (0 << WGM12) | (1 << CS12) | (0 << CS11) | (1 << CS10);

    TCNT1H = 0xFF;
    TCNT1L = 0xF0;

    MCUCR = (0 << ISC11) | (0 << ISC10) | (0 << ISC01) | (0 << ISC00);
    MCUCSR = (0 << ISC2);

#asm("sei")

    while (1) {

    }
}   