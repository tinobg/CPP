#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main() {
	Weapon club("crude spiked club");

	HumanA bob("Bob", club);
	bob.attack();
	club.setType("some other type of club");
	bob.attack();

	Weapon club2("another curde spiked club");
	
	HumanB jim("Jim");
	jim.attack();
	jim.setWeapon(club2);
	jim.attack();
	club2.setType("another type of club");
	jim.attack();

	return 0;
}