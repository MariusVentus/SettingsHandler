#include "SettingsHandler.h"
#include <fstream>

SettingsHandler::SettingsHandler(const std::string& SettingsFile)
	:
	m_SettingsLoc(SettingsFile)
{
	std::ifstream input(m_SettingsLoc);
	if (!input) {
		throw std::runtime_error("Bad File");
	}
}