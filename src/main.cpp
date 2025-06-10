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
  colorWipe(strip.Color(0, 0, 255), 25);
  delay(500);
  colorWipe(strip.Color(0, 255, 0), 25);
  delay(500);
  colorWipe(strip.Color(255, 0, 0), 25);
  delay(500);
}

//Taken from the strandtest example in the FastLED Neopixel Library
void colorWipe(uint32_t color, unsigned long wait) {
	for (unsigned int i = 0; i < strip.numPixels(); i++) {
		strip.setPixelColor(i, color);
		strip.show();
		delay(wait);
	}
}
