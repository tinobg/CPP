#include <iostream>  // Include this to use std::cout and std::endl
#include "Harl.hpp"

int main() {
    Harl harl;

    std::cout << "Complain at INFO level:" << std::endl;
    harl.complain("INFO");

    std::cout << "\nFilter at WARNING level:" << std::endl;
    harl.filter("WARNING");

    return 0;
}
