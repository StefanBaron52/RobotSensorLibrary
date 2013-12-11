#include <msp430g2553.h>
/*
 * sensor.h
 *
 *  Created on: Dec 5, 2013
 *      Author: C15Stefan.BaronvonVi
 */

#ifndef SENSOR_H_
#define SENSOR_H_


unsigned int rightsensor();

unsigned int leftsensor();

void initADC10();

void initLEDs();


#endif /* SENSOR_H_ */
