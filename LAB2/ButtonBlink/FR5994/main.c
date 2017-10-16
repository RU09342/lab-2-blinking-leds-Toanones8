#include <msp430.h>  //Contains all definitions for registers and built-in functions
int main(void)  //Main program
{
   WDTCTL = WDTPW + WDTHOLD; // Stop watchdog timer

   P1DIR |= BIT0; // Set P1.0 to output and P1.3 to input direction
   P1OUT &= ~BIT0; // set P1.0 to Off
   P5IE |= BIT6; // P1.3 interrupt enabled
   P5IFG &= ~BIT6; // P1.3 interrupt flag cleared
   P5REN |= BIT6;   // Enable Pull Up on (P1.3)
   //P5IES |= BIT6; // P1.3 Hi/lo edge

   PM5CTL0 &= ~LOCKLPM5;
   __bis_SR_register(GIE); // Enable all interrupts

   while(1) //Loop forever, we'll do our job in the interrupt routine...
   {}
}
  #pragma vector=PORT5_VECTOR
__interrupt void Port_5(void)
{
    P1OUT ^= BIT0;  // Toggle P1.0
    P5IFG &= ~BIT6; // P1.3 interrupt flag cleared
}
