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

#include <stdio.h>
#include <mega16.h>
#include <delay.h>

#asm
    .equ __lcd_port=0x18;
#endasm
#include <lcd.h>

int i;

void main(void){

    char alphabets[28] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

    PORTB = 0x00;
    DDRB = 0x00;
    lcd_init(16);

    
    lcd_clear();
    for(i = 0;i < 28;i++){
        if(i<15){
            lcd_gotoxy(i,0);
        }else{
            lcd_gotoxy(i % 15,1);
        }
        lcd_putchar(alphabets[i]);
        delay_ms(200);

    }

    while(1){
    }
            
}