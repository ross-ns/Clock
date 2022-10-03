#pragma once

#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>
#include "graphics.h"
#pragma comment(lib,"graphics.lib")

class Clock
{
	private:
		int cx;
		int cy;
		int radius;
		int outerFaceWeight;

		int hourMarkLength;
		int hourMarkWeight;
		int minuteMarkLength;
		int minuteMarkWeight;

		int secondHandLength;
		int secondHandWeight;
		int minuteHandLength;
		int minuteHandWeight;
		int hourHandLength;
		int hourHandWeight;

	public:
		Clock(int cx, int cy, int radius, int outerFaceWeight, int hourMarkLength, int hourMarkWeight, int minuteMarkLength, int minuteMarkWeight,
				int minuteHandLength, int minuteHandWeight, int hourHandLength, int hourHandWeight, int secondHandLength, int secondHandWeight)
		{
			this->cx = cx;
			this->cy = cy;
			this->radius = radius;
			this->outerFaceWeight = outerFaceWeight;

			this->hourMarkLength = hourMarkLength;
			this->hourMarkWeight = hourMarkWeight;
			this->minuteMarkLength = minuteMarkLength;
			this->minuteMarkWeight = minuteMarkWeight;
			
			this->secondHandLength = secondHandLength;
			this->secondHandWeight = secondHandWeight;
			this->minuteHandLength = minuteHandLength;
			this->minuteHandWeight = minuteHandWeight;
			this->hourHandLength = hourHandLength;
			this->hourHandWeight = hourHandWeight;
		}


		void drawFace()
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

		void drawHands()
		{
			for (int seconds = 0; seconds <= 360; seconds += 6)
			{
				setcolor(LIGHTBLUE);
				int handX = cx + (radius - minuteMarkLength) * cos(seconds * (M_PI / 180));
				int handY = cy + (radius - minuteMarkLength) * sin(seconds * (M_PI / 180));
				line(cx, cy, handX, handY);
				//drawFace(cx, cy, radius, outerFaceWeight, hourMarkLength, hourMarkWeight, minuteMarkLength, minuteMarkWeight);
				Sleep(1000);
				cleardevice();

				if (seconds == 360)
				{
					seconds = 0;
				}
			}
		}
};