#ifndef SLEEP_H
#define SLEEP_H

//this AVR library contains the methods that controls the sleep modes
#include <avr/sleep.h>
#include <Arduino.h>

extern int state;

extern int handlebar_button_pin;

extern int piezo_sensor_pin;

void sleep();
void wake_up();


#endif
