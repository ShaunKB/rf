#include "rfnt.h"

Hack::Hack(DWORD address, std::string enabled, std::string disabled)
{

	this->active = false;
	this->address = address;
	this->enabled = enabled;
	this->disabled = disabled;

}

void Hack::toggle()
{

	if (this->active)
		memapi::write(this->address, this->disabled);
	else
		memapi::write(this->address, this->enabled);

	this->active = !this->active;

}
