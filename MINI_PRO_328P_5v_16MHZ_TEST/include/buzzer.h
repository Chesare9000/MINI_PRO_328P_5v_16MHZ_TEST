#ifndef BUZZER_H
#define BUZZER_H

#include <Arduino.h>

//Parameters definitions


extern int buzzer_base_pin;

//Imperial March
extern int length;
extern int tempo;
extern String notes[];
extern String note_names[];
extern int tones[];
extern int beats[];

//Mario Theme
extern int tone1[];
extern int tone2[];
extern int delays[];


//Functions Definition


void buzzer_play_tone(int tone, int duration);

void buzzer_play_note(String note, int duration);

void buzzer_initialize();

void buzzer_play_imperial_march();

void buzzer_play_mario_theme();


#endif
