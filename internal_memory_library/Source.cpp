#include "memory/memory.hpp"

#include <iostream>

int health = 100ul;

int main()
{
	auto mem = memory();
	auto original_health = mem.read<int>(health);

	mem.write<int>(&health, 50);
	std::cout << "Original health: " << original_health << "\nNew Health: " << health << std::endl;
}