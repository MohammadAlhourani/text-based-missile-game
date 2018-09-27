//author mohammad alhourani
//date 20/09/2018

#include <iostream>
#include <math.h>
#include "Main.h"

float acquireTarget(unsigned int t_target[], Enemy &t_enemy);
void makeLaunchCode(unsigned int &t_code);
bool collision(Missile &t_warhead,Enemy t_enemy,  float &t_fuel);

int main()
{
	srand(time(nullptr));

	Missile warhead;
	Enemy target; 

	
	unsigned int launchCode;
	unsigned int inputCode = 0; // the code the user inputs

	unsigned int missileType = 2;

	unsigned int Target[2];

	float fuel = 0;

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
			std::cout << "that is not a missile type try again" << std::endl;
		}
	}

	static_cast<int> (distanceToTarget = acquireTarget(Target, target));

	std::cout << "target is " << distanceToTarget << " meters away" << std::endl;

	std::cout << "input how much fuel you want to use (1 fuel = 2 meters)" << std::endl;

	std::cin >> fuel;

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

	if (collision(warhead, target,fuel) == true)
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
	int distance = 0;

	t_target[0] = rand() % 1000 + 1;
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

bool collision(Missile &t_warhead, Enemy t_enemy, float &t_fuel)
{
	bool collision = false;

	while (t_fuel > 0)
	{
		t_fuel -= 1.115f;

		if (t_fuel > 0)
		{
			t_warhead.update();
		}
	}

	if (t_warhead.coordinates.x == t_enemy.coordinates.x &&
		t_warhead.coordinates.y == t_enemy.coordinates.y &&
		t_warhead.armed == true)
	{
		collision = true;
	}

	if (t_warhead.coordinates.x >= t_enemy.coordinates.x &&
		t_warhead.coordinates.x <= t_enemy.coordinates.x + 100 &&
		t_warhead.coordinates.y >= t_enemy.coordinates.y &&
		t_warhead.coordinates.y <= t_enemy.coordinates.y + 100 &&
		t_warhead.armed == true)
	{
		collision = true;
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
