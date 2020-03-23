#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bitset>

#include "Prontocode.h"

#define PAUSE std::cin.get()
#define PRINT_HEX_CODES 0

std::string gethex(std::string filename);

int main() {
	//std::string filename("power.txt");
	//std::string hexcode = gethex(filename);

	std::string hexcode("0000 006d 0022 0003 00a9 00a8 0015 003f 0015 003f 0015 003f 0015 0015 0015 0015 0015 0015 0015 0015 0015 0015 0015 003f 0015 003f 0015 003f 0015 0015 0015 0015 0015 0015 0015 0015 0015 0015 0015 0015 0015 003f 0015 0015 0015 0015 0015 0015 0015 0015 0015 0015 0015 0015 0015 0040 0015 0015 0015 003f 0015 003f 0015 003f 0015 003f 0015 003f 0015 003f 0015 0702 00a9 00a8 0015 0015 0015 0e6e");

	char* codep = &hexcode[0];

	Prontocode foo(codep);

	foo.print_info();

	std::cout << sizeof(long int) << std::endl;

		
	
	
	PAUSE;
	return 0;
}

std::string gethex(std::string filename) {
	std::string code;
	std::ifstream hexcode(filename);

	if (hexcode.is_open()) {
		std::getline(hexcode, code);
		return code;
	}
	else {
		std::cout << "Error: Unable to open: " << filename << std::endl;
		return "Error";
	}
}

