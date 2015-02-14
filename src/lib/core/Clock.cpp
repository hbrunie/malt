/*****************************************************
             PROJECT  : MATT
             VERSION  : 0.1.0-dev
             DATE     : 02/2015
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include <cassert>
#include "Clock.hpp"

/********************  NAMESPACE  *******************/
namespace MATT
{

/*******************  FUNCTION  *********************/
Clock::Clock()
{
	this->eventId = 0;
	this->lastEvent = 0;
	this->start = getticks();
}

/*******************  FUNCTION  *********************/
Clock::Clock(const Clock & clock)
{
	this->eventId = clock.eventId;
	this->lastEvent = clock.lastEvent;
	this->start = clock.start;
}

/*******************  FUNCTION  *********************/
ticks Clock::get ( ClockMode mode ) const
{
	assert(mode == CLOCK_TICKS || mode == CLOCK_ID);
	if (mode == CLOCK_TICKS)
		return getticks() - this->start;
	else
		return eventId;
}

/*******************  FUNCTION  *********************/
ticks Clock::getLastEventTime ( ClockMode mode ) const
{
	assert(mode == CLOCK_TICKS || mode == CLOCK_ID);
	if (mode == CLOCK_TICKS)
		return lastEvent;
	else
		return eventId;
}

/*******************  FUNCTION  *********************/
void Clock::markEvent ( void )
{
	eventId++;
	lastEvent = getticks() - this->start;
}

/*******************  FUNCTION  *********************/
ticks Clock::getStart ( void )
{
	return start;
}

};