#include "rpmControl.h"

rpmControl::rpmControl() {
	pinMode(_pinLED, OUTPUT);
	pinMode(_pinPWM, OUTPUT);
	pinMode(_pinPotentiometer, INPUT);
  pinMode(_pinSpeed, INPUT);

}

// Counting pulse using interrupts
 void rpmControl::readSpeed(){
      if (_half_revolutions >= _resolution) { 
     _rpm = 30*1000/(millis() - _timeold)*_half_revolutions;
     _timeold = millis();
     _half_revolutions = 0;
   }
  }

 void rpmControl::setRPMSpeed(){
  int wantedSpeed = analogRead(_pinPotentiometer);
  //DutyCyle for the PWM : from 0 to 255 (full Speedintint)
  int dutyCycle = map(wantedSpeed, 0, 1023, 0, 1023); // map to the range of the analog output
  int timerus = 1000000 ; 
  CurieTimerOne.pwmStart(_pinPWM,dutyCycle,timerus);
  }

 void rpmControl::rpm_fun()
 {
   _half_revolutions++;
   //Each rotation, this interrupt function is run twice
 }

