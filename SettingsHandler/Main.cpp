#include "SettingsHandler.h"
#include <iostream>

int main() {
	try {
		SettingsHandler g_Settings("Settings\\Settings.ini");
	}
	catch (std::runtime_error e) {
		std::cout << "Initialization error: " << e.what() << "\n";
	}

	std::cout << "End\n";
	std::cin.get();
	return 0;
}