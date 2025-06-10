# *Breath of the Wild*-themed Nintendo Switch Dock Modification

This repository contains the code used to control my *Breath of the Wild* themed Switch dock modification. Similar to some creative wireless phone chargers, it displays a light show (similar to an in-game Shiekah pedestal after Link interracts with it) when you dock the console in it.

## Hardware:
The hardware used in this project is:
- Seeed Studio XIAO SAMD21
- Adafruit NeoPixel Slim LED Dot Strand
- Original Switch Dock PCB (unmodified)

## Software:
The software is simple. The XIAO will detect when the switch is docked by hijacking the switch dock's already existing green status light signal (turns on when the console is docked and powered on). Then, it will do the flashy light show on the LEDs using the FastLED Neopixel library by Dave Madison.

### Notice:
I did not modify any Nintendo hardware or software in the making of this project. This repository contains no Nintendo software. I will not sell this as a product for profit. This is only for my own personal enjoyment and to practice my skills as an embedded software developer.