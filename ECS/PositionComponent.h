#pragma once

#include "Components.h"

class PositionComponent : public Component
{
private:
	int xpos;
	int ypos;

public:
	// By default start at 0,0
	PositionComponent()
	{
		xpos = 0;
		ypos = 0;
	}
	// Otherwise start at x, y
	PositionComponent(int x, int y)
	{
		xpos = x;
		ypos = y;
	}
	
	void update() override
	{
		xpos++;
		ypos++;
	}

	int x() { return xpos; }
	void x(int x) { ypos = x; }
	int y() { return ypos; }
	void y(int y) { ypos = y; }

	void setPos(int x, int y)
	{
		xpos = x;
		ypos = y;
	}
};
