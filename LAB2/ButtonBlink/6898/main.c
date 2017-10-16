/* Sam Toanone.. Button Blink..When Button 1.1 is pressed LED 1.0 is turned on.*/

#include <msp430.h>  //Contains definitions for msp430
int main(void)  //Main program
{
   WDTCTL = WDTPW + WDTHOLD; // Stop watchdog timer

   P1DIR |= BIT0; // Set P1.0 to output and P1.1 to input direction
   P1OUT &= ~BIT0; // set P1.0 to Off
   P1IE |= BIT1; // P1.1 interrupt enabled
   P1IFG &= ~BIT1; // Clear P1.1
   P1REN |= BIT1;   // Enable Pull Up resistor  on PIN 1.1



   __bis_SR_register(GIE); // Enable all interrupts


}
   #pragma vector=PORT1_VECTOR //Allow interrupt for button P.13
__interrupt void Port_1(void)
{
    P1OUT ^= BIT0;  // Toggle P1.0
    P1IFG &= ~BIT1; // P1.3 interrupt flag cleared
}
