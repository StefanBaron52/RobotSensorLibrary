/*
 * sensor.c
 *
 *  Created on: Dec 5, 2013
 *      Author: C15Stefan.BaronvonVi
 */


#include "sensor.h"
#include <msp430g2553.h>

void initLEDs() {

	P1DIR |= BIT0;
	P1DIR |= BIT6;

}

void initADC10() {

	ADC10CTL0 = ADC10SHT_3 + ADC10ON + ADC10IE;   //ADC10ON, interrupt enabled
	ADC10CTL1 |= ADC10SSEL1|ADC10SSEL0;         //Select SMCLK
	ADC10AE0 |= BIT3|BIT4|BIT5;
}

unsigned int leftsensor() {

	ADC10CTL0 &= ~ENC;
	ADC10CTL1 = INCH_3;
	ADC10AE0 |= BIT3;
	ADC10CTL0 |= ENC + ADC10SC;
	__bis_SR_register(CPUOFF + GIE);


	return ADC10MEM;

}

unsigned int rightsensor() {

	ADC10CTL0 &= ~ENC;
	ADC10CTL1 = INCH_4;
	ADC10AE0 |= BIT4;
	ADC10CTL0 |= ENC + ADC10SC;
	__bis_SR_register(CPUOFF + GIE);
	return ADC10MEM;

}


// ADC10 interrupt service routine
#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR(void)
{

  __bic_SR_register_on_exit(CPUOFF);        // Clear CPUOFF bit from 0(SR)
}
