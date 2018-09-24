//author mohammad alhourani
//date 20/09/2018

#include <iostream>
#include <math.h>
#include "Main.h"

float acquireTarget(unsigned int t_target[], Enemy &t_enemy);
void makeLaunchCode(unsigned int &t_code);
bool collision(Missile &t_warhead,Enemy t_enemy);

int main()
{
	srand(time(nullptr));

	Missile warhead;
	Enemy target; 

	
	unsigned int launchCode;
	unsigned int inputCode = 0; // the code the user inputs

	unsigned int missileType = 2;

	unsigned int Target[2];

	unsigned int fuel = 0;

	float distanceToTarget = 0;

	while (missileType == 2)
	{
		std::cout << "select what type of missile you would like? (explosive - 0) (nuclear - 1)" << std::endl;

		std::cin >> missileType;

		if (missileType == 1)
		{
			warhead.payload = NUCLEAR;
		}
		else if (missileType == 0)
		{
			warhead.payload = EXPLOSIVE;
		}
		else
		{
			missileType = 2;
			std::cout << "excuse me, that is not a missile type try again" << std::endl;
		}
	}

	ceil(distanceToTarget = acquireTarget(Target, target));

	std::cout << "target is " <<
	makeLaunchCode(launchCode);

	while (inputCode != launchCode)
	{
		std::cout << "enter the launch Code " << launchCode << std::endl;
		std::cin >> inputCode;

		if (inputCode == launchCode)
		{
			warhead.armed = true;
		}
		else
		{
			warhead.armed = false;

			std::cout << "wrong code try again" << std::endl;
		}
	}

	if (collision(warhead, target) == true)
	{
		std::cout << "target has been destroyed well done " << std::endl;
	}
	else
	{
		std::cout << "you missed the target" << std::endl;
	}

	std::system("pause");
	return 0;
}

float acquireTarget(unsigned int t_target[], Enemy &t_enemy)
{
	float distance = 0;

	t_target[0] = rand() % 50 + 1;
	t_target[1] = t_target[0] * 2;

	t_enemy.coordinates.x = t_target[0];
	t_enemy.coordinates.y = t_target[1];

	distance = sqrt(t_target[0] * t_target[0] + t_target[1] * t_target[1]);

	return distance;
}

void makeLaunchCode(unsigned int &t_code)
{
	t_code = rand() % 8999 + 1000;
}

bool collision(Missile &t_warhead, Enemy t_enemy)
{
	bool collision = false;

	while (t_warhead.coordinates.x <= t_enemy.coordinates.x &&
		t_warhead.coordinates.y <= t_enemy.coordinates.y &&
		t_warhead.armed == true && collision == false)
	{
		t_warhead.update();

		if (t_warhead.coordinates.x == t_enemy.coordinates.x &&
			t_warhead.coordinates.y == t_enemy.coordinates.y &&
			t_warhead.armed == true)
		{
			collision = true;
		}
	}

	if (t_warhead.coordinates.x > t_enemy.coordinates.x ||
		t_warhead.coordinates.y > t_enemy.coordinates.y &&
		t_warhead.armed == true)
	{
		collision = false;
		t_warhead.armed = false;
	}

	return collision;
}
