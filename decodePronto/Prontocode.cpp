#include <iostream>
#include <string>
#include <fstream>

#include "Prontocode.h"

Prontocode::Prontocode(std::string filename) {
				
} //Prontocode::Prontocode

int Prontocode::parse_prontocode(char cp) {
	//parse preamble
	d_learned = Prontocode::htow(cp) ? false : true;
	advance(cp, 1);
	d_freq = 1000000 / (Prontocode::htow(cp) * .241246);
	advance(cp, 1);
	d_seq1len = Prontocode::htow(cp);
	advance(cp, 1);
	d_seq2len = Prontocode::htow(cp);
	advance(cp, 1);
	if (d_seq1len) { //if length of sequence 1 is not zero:
		advance(cp, 2); //skip lead in pair, TODO: parse lead in pair

		int first_burst;
		int second_burst;
		for (int i = 0; i < (d_seq1len - 2); i++) {
			first_burst = htow(cp);
			advance(cp, 1);
			second_burst = htow(cp);
			if (first_burst != second_burst) {
				d_seq1_val |= ((d_seq1len - 3 - i) << 1);
			}
			advance(cp, 1);
		}
	}
}

std::string Prontocode::gethex(std::string filename) {
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

uint16_t Prontocode::htow(char cp) {
	return ((htob(cp[0]) << 12) | (htob(cp[1])) << 8) | (htob(cp[2]) << 4) | (htob(cp[3]));
}

uint16_t Prontocode::htob(char c) {
	if (is_hex(c)) {
		if ((c >= '0') && (c <= '9')) return (c - '0');
		if ((c >= 'a') && (c <= 'f')) return c - 'a' + 10;
		if ((c >= 'A') && (c <= 'F')) return c - 'A' + 10;
	}
	else {
		std::cout << "Prontocode::htob: Error: " << c << " is not valid hex digit." << std::endl;
		return 1;
	}
}

bool Prontocode::is_hex(char &c) {
	return (((c >= '0') && (c <= '9')) ||
		((c >= 'a') && (c <= 'f')) ||
		((c >= 'A') && (c <= 'F'))) ? true : false;
}

void Prontocode::print_info() {
	if (d_learned) std::cout << "learned: yes" << std::endl;
	else std::cout << "learned: no" << std::endl;
	std::cout << "freq: " << d_freq << " kHz" << std::endl;
	std::cout << "Sequence #1 Length: " << d_seq1len << std::endl;
	std::cout << "Sequence #2 Length: " << d_seq2len << std::endl;
}

void Prontocode::advance(char& cp, int times) {
	cp += (5 * times);
}





