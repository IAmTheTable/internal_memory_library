#include "memory/memory.hpp"

#include <iostream>

// comply with other auto practices
auto health = 100u;

int main()
{
	// no need to use auto if you're going to construct the class like this anyway
	memory mem;
	auto original_health = mem.read<int>(reinterpret_cast<std::uintptr_t>(&health));

	// no need to specify template type here, it's decided on compile time
	mem.write(reinterpret_cast<std::uintptr_t>(&health), 50u);
	std::cout << "Original health: " << original_health << "\nNew Health: " << health << std::endl;
}