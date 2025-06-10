#include "main.h"

void setup() {
  
  //PIN MODES
  pinMode(LED_DATA, OUTPUT);
  pinMode(DOCK_DET, INPUT_PULLUP);

  //Strip Initiation
  strip.begin();
  strip.setBrightness(50);
}

void loop() {
  while(digitalRead(DOCK_DET) != LOW) {}
  colorWipe(strip.Color(255, 100, 0), 0);
  delay(300);
  smoothSnake(100);
  smoothSnake(100);
  blank(300);
  colorWipe(strip.Color(0, 0, 255), 0);
  delay(300);
  blank(0);
  // colorWipe(strip.Color(255, 100, 0), 0);
  // colorWipe(strip.Color(0,0,50), 50);
  // colorWipe(strip.Color(0,0,100), 50);
  // colorWipe(strip.Color(0,0,255), 50);
}

//Taken from the strandtest example in the FastLED Neopixel Library
void colorWipe(uint32_t color, unsigned long wait) {
	for (unsigned int i = 0; i < strip.numPixels(); i++) {
		strip.setPixelColor(i, color);
		strip.show();
		delay(wait);
	}
}
void blank(unsigned long wait) {
	strip.clear();
	strip.show();
	delay(wait);
}

/**
 * @brief the "whoosh" at the end of the LED sequence
 */
void smoothFlash() {
  
}

/**
 * @brief snakes through each pixel with a fade in and fade out
 * @param wait: unsigned long, determines speed
 */
void smoothSnake(unsigned long wait) {
  for(int cur = -1; cur < 14; cur++) { //cursor will move through the outer circle of pattern
    for(int i = 0; i < 12; i++) {
      strip.setPixelColor(i, strip.Color(20, 4, 0));
    }
    if(cur - 1 >= 0 && cur - 1 <= 11) {
      strip.setPixelColor(cur - 1, strip.Color(0, 0, 20)); //medium brightness
    }
    if(cur >= 0 && cur <= 11) {
      strip.setPixelColor(cur, strip.Color(0, 0, 255)); //max brightness
    }
    if(cur + 1 >= 0 && cur + 1 <= 11) {
      strip.setPixelColor(cur + 1, strip.Color(0, 0, 20)); //medium brightness
    }

    strip.show();
    delay(wait);
  }
}
