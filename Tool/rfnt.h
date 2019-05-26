#pragma once
#include "includes.h"
#include "speed.h"
#include "memory.h"

class Hack
{
private:
	bool active;
	DWORD address;
	std::string enabled, disabled;

public:
	Hack(DWORD address, std::string enabled, std::string disabled);
	void toggle();
};
