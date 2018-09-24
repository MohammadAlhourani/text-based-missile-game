#pragma once

#include <iostream>
#include <cstdlib>  // include support for randomizing
#include <ctime>   // supports ctime function

enum WarHead { EXPLOSIVE, NUCLEAR };


typedef struct Position
{
	int x = 0;
	int y = 0;

	void print()
	{
		std::cout << x << y << std::endl;
	}

}Coordinates;

typedef struct Enemy {
	Coordinates coordinates;
}Target;


struct Missile {
	WarHead payload;

	Coordinates coordinates;

	Target target;

	bool armed;

	/*void arm()
	{
		if (armed)
			armed = false;
		else
			armed = true;
	}*/

	void update() {
		coordinates.x += 1;
		coordinates.y += 2;
	}
};
