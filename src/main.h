#ifndef MAIN_H
#define MAIN_H

#include <FastLED_NeoPixel.h>
#include <Arduino.h>

//PIN DEFINITIONS
#define LED_DATA 6
#define DOCK_DET 10

//OTHER MACROS
#define NUM_LEDS 20

//Global
FastLED_NeoPixel<NUM_LEDS, LED_DATA, NEO_GRB> strip;

//Function Declarations
void colorWipe(uint32_t color, unsigned long wait);
void blank(unsigned long wait);
void smoothFlash();
void smoothSnake(unsigned long wait);

#endif