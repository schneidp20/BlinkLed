#include <Adafruit_NeoPixel.h>

class BlinkLed{

public:
	BlinkLed(Adafruit_NeoPixel *strip, byte(*pix)[MAXSINGLEROW], byte pixmax, byte red, byte green, byte blue, long freq);
	
	// Call this on each loop iteration and Blink will automatically do the blink frequency.
	// on - true, the method will do the blink frequency
	//      false, turn off the LEDs. 
	void Blink(bool on);

	// Just turn on/off the LEDs w/o blink frequency.   
	void Set(bool on);



private:
	void set(bool on);
	Adafruit_NeoPixel *_strip;
	byte (*_pix)[MAXSINGLEROW];
	byte _pixmax;
	byte _red;	
	byte _green;
	byte _blue;
	long _freq;

	bool _currentlyon;
	bool _blinkon;
	long _nextIteration;
	
};