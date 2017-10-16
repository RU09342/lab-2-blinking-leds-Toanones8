/* Sam Toanone.. Button Blink..When Button 1.3 is pressed LED 1.0 is turned on.*/

#include <msp430.h>  //Contains definitions for msp430
int main(void)  //Main program
{
   WDTCTL = WDTPW + WDTHOLD; // Stop watchdog timer

   P1DIR |= BIT0; // Set P1.0 to output and P1.3 to input direction
   P1OUT &= ~BIT0; // set P1.0 to Off
   P1IE |= BIT3; // P1.3 interrupt enabled
   P1IFG &= ~BIT3; // Clear P1.3
   P1REN |= BIT3;   // Enable Pull Up resistor  on PIN 1.3



   __bis_SR_register(GIE); // Enable all interrupts


}
   #pragma vector=PORT1_VECTOR //Allow interrupt for button P.13
__interrupt void Port_1(void)
{
    P1OUT ^= BIT0;  // Toggle P1.0
    P1IFG &= ~BIT3; // P1.3 interrupt flag cleared
}
