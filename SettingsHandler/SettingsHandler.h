#pragma once
#include <string>

class SettingsHandler {
public:
	SettingsHandler(const std::string& SettingsFile);
private:
	const std::string m_SettingsLoc;
	void RefreshSettings(void); //Refreshes settings from the input file.
	void SaveSettings(void) const; //Save Current Settings in file. 
	void ReadLineAndClean(std::ifstream& inStream, std::string& inString);
	void ScrubLine(std::string& inString);
	bool Stob(std::string inString) const;
};