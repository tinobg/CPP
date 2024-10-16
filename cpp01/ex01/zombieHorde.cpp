#include "Zombie.hpp"
#include <cstdio>

Zombie* zombiehorde(int N, std::string name) {
	if (N <= 0)
		return NULL;

	Zombie* horde = new Zombie[N];

	for (int i = 0; i < N; ++i) {
		char numberedName[50];
		std::sprintf(numberedName, "%s%d", name.c_str(), i + 1);
		horde[i].setName(numberedName);
	}

	return horde;
}