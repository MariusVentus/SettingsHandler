#pragma once
#include <string>

class SettingsHandler {
public:
	SettingsHandler(const std::string& SettingsFile);
private:
	const std::string m_SettingsLoc;
};