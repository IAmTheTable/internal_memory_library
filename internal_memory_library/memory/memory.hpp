#pragma once
#include <Windows.h>
#include <string>

class memory
{
	std::uintptr_t current_handle;

public:

	memory(std::string&& mod) { current_handle = reinterpret_cast<std::uintptr_t>(GetModuleHandleA(mod.c_str())); };
	memory() = default;

	template<class T>
	T read(std::uintptr_t address)
	{
		if (current_handle)
			return T(reinterpret_cast<T*>(current_handle + address));

		return T(reinterpret_cast<T*>(address));
	}

	template<class T>
	void write(void* address, T value)
	{

		if (current_handle)
			*reinterpret_cast<T*>(current_handle + reinterpret_cast<std::uintptr_t>(&address)) = value;

		*reinterpret_cast<T*>(address) = value;
	}
};