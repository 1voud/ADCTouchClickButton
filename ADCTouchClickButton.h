#ifndef ADCTouchClickButton_H
#define ADCTouchClickButton_H

#if (ARDUINO <  100)
#include <WProgram.h>
#else
#include <Arduino.h>
#endif

#define CLICKBTN_PULLUP HIGH

#ifndef ADCT_h
#define ADCT_h
#endif

class ADCTouchClickButton
{
  public:
    ADCTouchClickButton(uint8_t buttonPin, int adcSamples, int adcLimit);
    ADCTouchClickButton(uint8_t buttonPin, int adcSamples, int adcLimit, boolean active);
    void Update();
    void createReference(int adcSamples);
    int clicks;                   // button click counts to return
    boolean depressed;            // the currently debounced button (press) state (presumably it is not sad :)
    long debounceTime;
    long multiclickTime;
    long longClickTime;

    int limit;	
    int samples;
    int touchRef; 
  private:
    uint8_t _pin;                 // Arduino pin connected to the button
    boolean _activeHigh;          // Type of button: Active-low = 0 or active-high = 1
    boolean _btnState;            // Current appearant button state
    boolean _lastState;           // previous button reading
    int _clickCount;              // Number of button clicks within multiclickTime milliseconds
    long _lastBounceTime;         // the last time the button input pin was toggled, due to noise or a press
    int read();
};


#endif