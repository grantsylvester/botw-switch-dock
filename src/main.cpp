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
  smoothFlash(10 * 255, 255, 255, 5);
  delay(300);
  smoothSnake(100);
  smoothSnake(100);
  smoothFlash(128 * 255, 255, 255, 10);
  blank(0);
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
 * @param hue: uint16_t HSV Hue (scale H to 255 then multiply by 255)
 * @param sat: uint8_t HSV Saturation
 * @param max_value: int peak brightness of flash
 * @param wait: delay between each change in brightness
 */
void smoothFlash(uint16_t hue, uint8_t sat, int max_value, unsigned long wait) {
  for(int value = 0; value <= max_value; value += 5) {
    for(unsigned int i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, strip.ColorHSV(hue, sat, value));
    }
    strip.show();
    delay(wait);
  }
  for(int value = max_value; value >= 0; value -= 5) {
    for(unsigned int i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, strip.ColorHSV(hue, sat, value));
    }
    strip.show();
    delay(wait);
  }
}

/**
 * @brief snakes through each pixel with a fade in and fade out
 * @param wait: unsigned long, determines speed
 */
void smoothSnake(unsigned long wait) {
  for(int cur = -1; cur < 14; cur++) { //cursor will move through the outer circle of pattern
    for(int i = 0; i < strip.numPixels(); i++) {
      if(i <= 11) {
        strip.setPixelColor(i, strip.ColorHSV(10 * 255, 255, 50));
      } else {
        strip.setPixelColor(i, strip.ColorHSV(10 * 255, 255, 200));
      }
    }
    if(cur - 1 >= 0 && cur - 1 <= 11) {
      strip.setPixelColor(cur - 1, strip.ColorHSV(128 * 255, 255, 100)); //medium brightness
    }
    if(cur >= 0 && cur <= 11) {
      strip.setPixelColor(cur, strip.ColorHSV(128 * 255, 255, 255)); //max brightness
    }
    if(cur + 1 >= 0 && cur + 1 <= 11) {
      strip.setPixelColor(cur + 1, strip.ColorHSV(128 * 255, 255, 100)); //medium brightness
    }

    strip.show();
    delay(wait);
  }
}
