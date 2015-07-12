//
//  SQRGBLED.cpp
//  
//
//  Created by Bradley Clayton on 7/30/12.
//  Copyright (c) 2012 Squarepolka. All rights reserved.
//


#include "SQRGBLED.h"

SQRGBLED::SQRGBLED()
{
    
}

void SQRGBLED::setup(int redPin, int greenPin, int bluePin)
{
    _redLED.setup(redPin);
    _greenLED.setup(greenPin);
    _blueLED.setup(bluePin);
}

void SQRGBLED::colour(int red, int green, int blue, long duration)
{
    _redLED.fadeToBrightness(red, duration);
    _greenLED.fadeToBrightness(green, duration);
    _blueLED.fadeToBrightness(blue, duration);
    
    // Immediately set the colour if the duration is 0
    if (duration <= 0)
    {
        this->loop();
    }
}

boolean SQRGBLED::isFading()
{
    return _redLED.isFading || _greenLED.isFading || _blueLED.isFading;
}

boolean SQRGBLED::isPulsing()
{
    return _redLED.isPulsing || _greenLED.isPulsing || _blueLED.isPulsing;
}

float SQRGBLED::currentRedVal()
{
    return _redLED.currentVal();
}

float SQRGBLED::currentGreenVal()
{
    return _greenLED.currentVal();
}

float SQRGBLED::currentBlueVal()
{
    return _blueLED.currentVal();
}

float SQRGBLED::currentAverageVal()
{
    return _redLED.currentVal() + _greenLED.currentVal() + _blueLED.currentVal() / 3;
}

#pragma mark - SQSchedularDelegate Methods
unsigned int SQRGBLED::executionInterval()
{
    return 0;
}

// Clock events
void SQRGBLED::loop()
{
    // Forward loop event
    if (_redLED.isFading)
    {
        _redLED.loop();
    }
    if (_greenLED.isFading)
    {
        _greenLED.loop();
    }
    if (_blueLED.isFading)
    {
        _blueLED.loop();
    }
}