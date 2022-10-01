#define _USE_MATH_DEFINES
#include <Windows.h>

#include <cmath>
#include <iostream>
#include "graphics.h"
#pragma comment(lib,"graphics.lib")


void drawFace(int cx, int cy, int radius, int outerFaceWeight, int hourMarkLength, int hourMarkWeight, int minuteMarkLength, int minuteMarkWeight);

int main()
{
	int radius =					200;	// Clock face radius
	int outerFaceWeight =			4;		// Weight of the outer circle of the clock face
	int hourMarkLength =			25;		// Length of the hour markers
	int hourMarkWeight =			3;		// Weight of hour marker lines
	int minuteMarkLength =			10;		// Length of the minute markers
	int minuteMarkWeight =			1;		// Weight of the minute markers

	// Initialise graphics
	int gd = DETECT, gm;
	initgraph(&gd, &gm, (char*)"");

	int cx = getmaxx() / 2;					// Centre x coordinate of current window
	int cy = getmaxy() / 2;					// Centre y coordinate of current window


	drawFace(cx, cy, radius, outerFaceWeight, hourMarkLength, hourMarkWeight, minuteMarkLength, minuteMarkWeight);
	

	

	for (int seconds = 0; seconds <= 360; seconds+=6)
	{
		setcolor(LIGHTBLUE);
		int handX = cx + (radius - minuteMarkLength) * cos(seconds * (M_PI / 180));
		int handY = cy + (radius - minuteMarkLength) * sin(seconds * (M_PI / 180));
		line(cx, cy, handX, handY);
		drawFace(cx, cy, radius, outerFaceWeight, hourMarkLength, hourMarkWeight, minuteMarkLength, minuteMarkWeight);
		Sleep(1000);
		cleardevice();

		if (seconds == 360)
		{
			seconds = 0;
		}
	}


	getch();
	closegraph();

	return 0;
}

void drawFace(int cx, int cy, int radius, int outerFaceWeight, int hourMarkLength, int hourMarkWeight, int minuteMarkLength, int minuteMarkWeight)
{
	setcolor(WHITE);
	// Draw the outer clock face
	setlinestyle(SOLID_LINE, 0, outerFaceWeight);
	circle(cx, cy, radius);

	// Draw marks on clock face
	double x1, y1, x2, y2;

	// Hour markers first
	setlinestyle(SOLID_LINE, 0, hourMarkWeight);
		
	for (int angle = 0; angle < 360; angle += 30)
	{
		x1 = cx + radius * cos(angle * (M_PI / 180));
		y1 = cy + radius * sin(angle * (M_PI / 180));

		x2 = cx + (radius - hourMarkLength) * cos(angle * (M_PI / 180));
		y2 = cy + (radius - hourMarkLength) * sin(angle * (M_PI / 180));

		line(x1, y1, x2, y2);
	}

	// Minute markers
	setlinestyle(SOLID_LINE, 0, minuteMarkWeight);

	for (int angle = 0; angle < 360; angle += 6)
	{
		if (angle % 10 != 0)
		{
			x1 = cx + radius * cos(angle * (M_PI / 180));
			y1 = cy + radius * sin(angle * (M_PI / 180));

			x2 = cx + (radius - minuteMarkLength) * cos(angle * (M_PI / 180));
			y2 = cy + (radius - minuteMarkLength) * sin(angle * (M_PI / 180));

			line(x1, y1, x2, y2);
		}
	}
}