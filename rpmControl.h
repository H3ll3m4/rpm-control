// rpmControl.h

#ifndef _rpmCONTROL_h
#define _rpmCONTROL_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "CurieTimerOne.h"

class rpmControl {
public: 
  rpmControl();
  void readSpeed();
  void setRPMSpeed();


private:
  int _pinPotentiometer = A0;
  int _pinPWM = 9;
  int _pinSpeed = 3; 
  volatile byte _half_revolutions;
  unsigned int _rpm;
  unsigned long _timeold;
  int _resolution = 40;// Resolution: how often update RPM, use 30. Can increase for better resolution or decrease for faster result
  void rpm_fun();
};

#endif

