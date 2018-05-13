#include <Adafruit_NeoPixel.h>
#include <ArrayConstants.h> // WARNING: check these constants before compiling, it may need changing between sketches
#include "BlinkLed.h"

BlinkLed::BlinkLed(Adafruit_NeoPixel *strip, byte(*pix)[MAXSINGLEROW], byte pixmax, byte red, byte green, byte blue, long freq)
{	
	_strip = strip;
	_pix = pix;      
	_pixmax = pixmax;	
	_red = red;
	_green = green;
	_blue = blue;		
	_freq = freq;
	
	_currentlyon = false;
	_blinkon = false;
	_nextIteration = 0 ;
}

void BlinkLed::Blink(bool on)
{ 
  if (on)
  {
    _currentlyon = true;
    long now = millis();
    if (_nextIteration < now)
    {
		_nextIteration = now + _freq;
		set(!_blinkon); // set to opposite of its current state
    }
  }
  else
  {
    if (_currentlyon) // only turn off if it's currently on
	{
		_currentlyon = false;
		set(false); // turn off
	}
  }
}

void BlinkLed::set(bool on)
{
	_blinkon= on;
	for (int x = 0; x<_pixmax; x++)
	{
		if (_blinkon)
		{     
			_strip->setPixelColor((*_pix)[x], _strip->Color(_red, _green, _blue));
		}
		else
		{
			_strip->setPixelColor((*_pix)[x], _strip->Color(0,0,0));
		}
	}
	_strip->show();
}

void BlinkLed::Set(bool on)
{
	for (int x = 0; x<_pixmax; x++)
	{
		if (on)
		{     
			_strip->setPixelColor((*_pix)[x], _strip->Color(_red, _green, _blue));
		}
		else if (_currentlyon) // only turn off if it's currently on
		{
			_strip->setPixelColor((*_pix)[x], _strip->Color(0,0,0));
		}
	}
	_strip->show();
	_currentlyon = on;
}

