#pragma once
#include <Windows.h>
#include <string>

class memory
{
	// provide default initialization for current_handle
	std::uintptr_t current_handle = 0;

public:

	// rvalue usage on std::string should not be permitted nor used here, if c_str is going to be substituted.
	// initialization of current_handle can be in the initializer list for the constructor
	memory(const char* const mod) : current_handle{ reinterpret_cast<std::uintptr_t>(GetModuleHandleA(mod)) } {};

	// current_handle has no default value, if constructed with no parameters it will be undefined.
	memory() = default;

	// this will not work, it will need to be casted twice in order to PROPERLY use this function
	// will break on sizes < sizeof(void*)
	template<class T>
	T read(std::uintptr_t address)
	{
		return *reinterpret_cast<T*>(current_handle ? current_handle + address : address);
	}

	// comply with the read definition, and fix for pointers as well
	// &address is not valid in this scenario.
	template<class T>
	void write(std::uintptr_t address, T value)
	{
		*reinterpret_cast<T*>(current_handle ? current_handle + address : address) = value;
	}
};