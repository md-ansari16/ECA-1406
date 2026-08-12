#include <reg51.h>

sbit PWM = P1^0;

unsigned char count = 0;
unsigned char duty = 150;

void timer0_ISR(void) interrupt 1
{
    TH0 = 0xFC;
    TL0 = 0x66;

    count++;

    if(count < duty)
        PWM = 1;
    else
        PWM = 0;

    if(count >= 200)
        count = 0;
}

void main()
{
    TMOD = 0x01;
    TH0 = 0xFC;
    TL0 = 0x66;

    IE = 0x82;
    TR0 = 1;

    while(1);
}