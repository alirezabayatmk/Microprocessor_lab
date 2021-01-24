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

// for common anode 7seg
int ovf_count = 0;
int num = 0;

interrupt [TIM1_OVF] void timer1_ovf_isr(void)
{
    ovf_count++;
    if(ovf_count == 5){
        if(num < 10){
            PORTD =  num;
        } else {
            num = 0 ;
            PORTD = num;
        }
        num++;
    }

    TCNT1H=0xFF;
    TCNT1L=0xF0;
}

void main(void)
{
    DDRD=0xff;
    TCCR1A=0x00;
    TCCR1B=0x01;
    TCNT1H=0xFF;
    TCNT1L=0xF0;
    MCUCR=(0<<ISC11) | (0<<ISC10) | (0<<ISC01) | (0<<ISC00);
    MCUCSR=(0<<ISC2);
    TIMSK=0x04;
    #asm("sei")
    while (1) {

    }
}