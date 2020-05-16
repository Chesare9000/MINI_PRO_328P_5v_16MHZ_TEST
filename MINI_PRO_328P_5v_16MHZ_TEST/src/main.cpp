#ifndef ARDUINO_H
#define ARDUINO_H

#include <Arduino.h>

#endif
//-------------------------------------------------------------------------

#include "buzzer.h"
#include "sleep.h"
#include "gps_fona.h"
#include "piezo_sensor.h"
#include "flip_flops.h"
//#include ".h"



void setup()
{
  Serial.begin(115200);//Start Serial Comunication

  buzzer_initialize();
  buzzer_play_mario_theme();

  sleep();


}

void loop()
{


}
