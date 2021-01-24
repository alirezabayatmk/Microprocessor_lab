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


void main(void){
    PORTB = 0x00;
    DDRB = 0x00;
    lcd_init(16);
    
    
    lcd_clear();
    lcd_gotoxy(0,0);
    lcd_putsf("Hello,World!");
}