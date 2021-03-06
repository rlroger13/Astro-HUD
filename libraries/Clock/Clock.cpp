/*
  Clock.cpp - Library for
  ...
*/

#include "Clock.h"

//Constructor for processor speed in MHz
Clock::Clock(
{
  interval = 1000;
  hour=0;
  min=0;
  sec=0;
  prevMillis=0;
  currentMillis=millis();
}

void Clock::constraints()
{
  if(sec > 59)
  {
    min += 1;
    sec = 0;
  }
  if (min > 59)
  {
    hour += 1;
    min = 0;
  }
}

void Clock::update()
{
  if((currentMillis - prevMillis) > interval)
  {
    sec++;
    prevMillis = currentMillis;
    constraints();
  }
}
