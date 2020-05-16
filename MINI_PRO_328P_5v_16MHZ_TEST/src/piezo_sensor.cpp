
#include <piezo_sensor.h>

int piezo_sensor_pin = 3 ;

int piezo_sensor_base = 4;

void piezo_sensor_initialize()
{
  pinMode(piezo_sensor_pin,INPUT);
  pinMode(piezo_sensor_base,OUTPUT);
  digitalWrite(piezo_sensor_base,LOW);

}

void piezo_sensor_activate()
{
  digitalWrite(piezo_sensor_base,HIGH);
}
