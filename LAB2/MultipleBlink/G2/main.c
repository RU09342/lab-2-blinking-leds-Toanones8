#include <msp430.h>

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;       // stop watchdog timer
    P1OUT &= ~0x01;                 // Clear P1.0 output latch for a defined power-on state
    P1DIR |= BIT0;                  // configure P1.6 as output
    P1DIR |= BIT6;                  // configure P1.0 as output

   int i = 0;   // volatile to prevent optimization
   int j = 0;


    while(1)
    {
        i ++;
        j++;
        if(i>30000)
        {i=0;P1OUT^=BIT6;}
        if(j>10000)
        {j=0;P1OUT^=BIT0;}

        }
    }
