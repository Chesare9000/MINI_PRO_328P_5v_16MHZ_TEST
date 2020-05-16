#include <Arduino.h>
#include "sleep.h"
#include "piezo_sensor.h"

int handlebar_button_pin = 2 ;

int state = 0 ;


void wake_up()
{
  state = 1 ; //Woke up for the first time

  sleep_disable();//Disable sleep mode
  detachInterrupt(0); //Removes the interrupt from pin 2;
  detachInterrupt(1); //Removes the interrupt from pin 3;
}


void alarm_activated()
{
  state = 2 ;

  sleep_disable();//Disable sleep mode
  detachInterrupt(0); //Removes the interrupt from pin 2;
  detachInterrupt(1); //Removes the interrupt from pin 3;
}


void wake_up_decisions(int state)
{
  switch(state)
  {
    case 1 :
      Serial.println("First Wake UP , activating Piezo Sensor");
      piezo_sensor_activate();
      delay(2000);
      Serial.println("Going Back to Sleep");
      sleep();
      break;

    case 2 :
      Serial.println("Alarm Triggered");
      delay(2000);
      Serial.println("\nWaiting for the Alarm to Stabilize ....");
      int count = 0 ;

      while(1)
      {
        //Wait three seconds until sleeping again
        if(!digitalRead(piezo_sensor_pin)) count = 0;
        else if (count>5000)break;
        else count++;
        delay(1);
      }
      Serial.println("Back to Sleep! ");
      sleep();
      break;

  }
}


void sleep()
{
    sleep_enable();//Enabling sleep mode

    pinMode(handlebar_button_pin,INPUT);

    attachInterrupt(digitalPinToInterrupt(handlebar_button_pin), wake_up, FALLING);//attaching a interrupt to pin d2
    attachInterrupt(digitalPinToInterrupt(piezo_sensor_pin), alarm_activated, FALLING);//attaching a interrupt to pin d2

    set_sleep_mode(SLEEP_MODE_PWR_DOWN);//Setting the sleep mode, in our case full sleep
    digitalWrite(LED_BUILTIN,LOW);//turning LED off
    Serial.println("OK , so I'm heading out , see ya later alligator");
    delay(3000); //wait a second to allow the led to be turned off before going to sleep
    sleep_cpu();//activating sleep mode

    //Once woke up
    Serial.println("what's the crack baee!");//next line of code executed after the interrupt
    digitalWrite(LED_BUILTIN,HIGH);//turning LED on

    delay(2000);

    wake_up_decisions(state);

  }
