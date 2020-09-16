#include "SettingsHandler.h"
#include <fstream>

SettingsHandler::SettingsHandler(const std::string& SettingsFile)
	:
	m_SettingsLoc(SettingsFile)
{
	std::ifstream input(m_SettingsLoc);
	if (!input) {
		throw std::runtime_error("Bad Settings File");
	}
	else {
		RefreshSettings();
	}
}

void SettingsHandler::RefreshSettings(void)
{
	std::ifstream input(m_SettingsLoc);
	if (input) {
		std::string token = "";
		do {
			ReadLineAndClean(input, token);

		} while (!input.eof() && !token.empty());
	}
	else {
		throw std::runtime_error("Bad Settings File at Refresh. Overwriting with Default.");
		SaveSettings();
	}
}

void SettingsHandler::SaveSettings(void) const
{
}

void SettingsHandler::ReadLineAndClean(std::ifstream& inStream, std::string& inString)
{
	inString.clear();
	std::getline(inStream, inString);
	ScrubLine(inString);
}

void SettingsHandler::ScrubLine(std::string& inString)
{
	//Remove ";" Comments
	if (inString.find(";") != std::string::npos) {
		inString.erase(inString.find(";"));
	}
	//Remove Double White Space
	while (inString.find("  ") != std::string::npos) {
		inString.erase(inString.find("  "), 1);
	}
	//Remove Horiz Tabs
	while (inString.find("\t") != std::string::npos) {
		inString.erase(inString.find("\t"), 1);
	}
	//Remove Vert Tabs
	while (inString.find("\v") != std::string::npos) {
		inString.erase(inString.find("\v"), 1);
	}
	//Remove Carriage Return
	while (inString.find("\r") != std::string::npos) {
		inString.erase(inString.find("\r"), 1);
	}
	//Remove Newline
	while (inString.find("\n") != std::string::npos) {
		inString.erase(inString.find("\n "), 1);
	}
}

bool SettingsHandler::Stob(std::string inString) const
{
	//Lower all Letters
	for (unsigned i = 0; i < inString.size(); i++) {
		if (inString[i] >= 65 && inString[i] <= 90) {
			inString[i] = inString[i] + 32; //Make into lowercase
		}
	}
	//Bool
	if (inString == "true") {
		return true;
	}
	else if (inString == "false") {
		return false;
	}
	else {
		return false;
	}
}
