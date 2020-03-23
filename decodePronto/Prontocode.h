#ifndef PRONTOCODE_H
#define PRONTOCODE_H

#include <iostream>
#include <string>

class Prontocode {
	float d_tol = 0.1;

	bool d_learned;
	int d_freq;
	short d_seq1len;
	short d_seq2len;
	enum sequence { first, second }; //define if sequence is first or second
	short length;  //number of burst pairs
	int d_seq1_val = 0;


public:
	Prontocode(std::string filename);


	int parse_prontocode(char cp);

	std::string gethex(std::string filename);

	uint16_t htow(char cp);

	uint16_t htob(char c);

	bool is_hex(char &c);

	void print_info();

	void advance(char& cp, int times);

};

#endif //PRONTOCODE_H
