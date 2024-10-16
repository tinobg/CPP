#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon) {}

void HumanA::attack() const {
	std::cout << name << " attack with their " << weapon.getType() << std::endl;
	
}
