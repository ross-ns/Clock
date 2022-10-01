#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include "graphics.h"
#pragma comment(lib,"graphics.lib")


int main()
{
	int outerRadius =				200;	// Clock face radius
	int innerRadius = outerRadius - 25;		// Inner radius for ticks
	int outerLineWeight =			5;		// Weight of the outer face circle
	int tickWeight =				4;		// Weight of the tick lines

	// Initialise graphics
	int gd = DETECT, gm;
	initgraph(&gd, &gm, (char*)"");

	int cx = getmaxx() / 2;					// Centre x coordinate of the current window
	int cy = getmaxy() / 2;					// Centre y coordinate of the current window


	// Draw the outer clock face
	setlinestyle(SOLID_LINE, 0, outerLineWeight);
	circle(cx, cy, outerRadius);

	// Draw the ticks on the clock face
	double x1, y1, x2, y2;
	setlinestyle(SOLID_LINE, 0, tickWeight);

	for (int angle = 0; angle < 360; angle += 30)
	{
		x1 = cx + outerRadius * cos(angle * (M_PI / 180));
		y1 = cy + outerRadius * sin(angle * (M_PI / 180));

		x2 = cx + innerRadius * cos(angle * (M_PI / 180));
		y2 = cy + innerRadius * sin(angle * (M_PI / 180));

		line(x1, y1, x2, y2);
	}


	getch();
	closegraph();

	return 0;
}