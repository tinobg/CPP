#include "Zombie.hpp"

int main() {
	int numberOfZombies = 5;
	Zombie* horde = zombieHorde(numberOfZombies, "HordeZombie");

	for (int i = 0; i < numberOfZombies; ++i) {
		horde[i].announce();
	}

	delete[] horde;
	return 0;
}