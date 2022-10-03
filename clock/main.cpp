#define _USE_MATH_DEFINES
#include <Windows.h>

#include <cmath>
#include <iostream>
#include "graphics.h"
#include "Clock.h"
#pragma comment(lib,"graphics.lib")

int main()
{
	int radius =			200;	// Clock face radius
	int outerFaceWeight =	4;		// Weight of the outer circle of the clock face
	
	int hourMarkLength =	25;		// Length of the hour markers
	int hourMarkWeight =	3;		// Weight of hour marker lines
	int minuteMarkLength =	10;		// Length of the minute markers
	int minuteMarkWeight =	1;		// Weight of the minute markers
	
	int hourHandLength =	20;
	int hourHandWeight =	4;
	int minuteHandLength =	15;
	int minuteHandWeight =	2;
	int secondHandLength =	18;
	int secondHandWeight =	1;


	// Initialise graphics
	int gd = DETECT, gm;
	initgraph(&gd, &gm, (char*)"");

	int cx = getmaxx() / 2;			// Centre x coordinate of current window
	int cy = getmaxy() / 2;			// Centre y coordinate of current window


	Clock clock(cx, cy, radius, outerFaceWeight, hourMarkLength, hourMarkWeight, minuteMarkLength, minuteMarkWeight,
				minuteHandLength, minuteHandWeight, hourHandLength, hourHandWeight, secondHandLength, secondHandWeight);
	
	clock.drawFace();
	clock.drawHands();


	getch();
	closegraph();

	return 0;
}


