//
//  SQRGBLED.h
//  
//
//  Created by Bradley Clayton on 7/30/12.
//  Copyright (c) 2012 Squarepolka. All rights reserved.
//

#ifndef SQRGBLED_h
#define SQRGBLED_h

#include "Arduino.h"
#include "SQSchedularProtocol.h"
#include "SQLED.h"

class SQRGBLED : public SQSchedularProtocol
{
public:
    SQRGBLED();
    virtual void setup(int redPin, int greenPin, int bluePin);
    virtual void colour(int red, int green, int blue, long duration);
	virtual boolean isFading();
	virtual boolean isPulsing();
	virtual float currentRedVal();
	virtual float currentGreenVal();
	virtual float currentBlueVal();
	virtual float currentAverageVal();

    #pragma mark - SQSchedularDelegate Methods
    virtual unsigned int executionInterval();
    virtual void loop();

private:
    SQLED _redLED;
    SQLED _greenLED;
    SQLED _blueLED;
};

#endif