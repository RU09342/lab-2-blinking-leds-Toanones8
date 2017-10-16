#include <msp430.h>

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;       // stop watchdog timer
    P1OUT &= ~0x01;                 // Clear P1.0 output latch for a defined power-on state
    P1DIR |= BIT0;                  // configure P1.6 as output
    P2DIR |= BIT0;                  // configure P1.0 as output

   int i = 0;   // volatile to prevent optimization
   int j = 0;

  // PM5CTL0 &= ~LOCKLPM5;           // Disable the GPIO power-on default high-impedance mode
                                     // to activate previously configured port settings

    while(1)
    {
        i ++;
        j++;
        if(i>30000)
        {i=0;P2OUT^=BIT0;}
        if(j>10000)
        {j=0;P1OUT^=BIT0;}

        }
    }
