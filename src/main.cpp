#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "bin/data_types_conversion.h"

int main(int nrargs, char *args[]){
	char memory[65535];

	std::cout << args[1] << "\n";

	for(int x = 0; x<65536; x++){
		memory[x] = '\x00';
	}
	
	std::ifstream rom;
	rom.open(args[1]);
	rom.get(memory,65535);
	rom.close();

	if(memory[0x0104]!='\xce' || memory[0x0105]!='\xed'){
		std::cout << "ERROR: wrong Nintendo graphic opcodes! Found: " << memory[0x0104] << memory[0x0105] << "\n";
	}else{
		std::cout << "Nintendo graphic opcodes: OK\n";
	}

	std::cout << "Game title: ";
	char title[0x0142-0x0134];
	for(int x = 0; x<(0x0142-0x0134+1); x++){
		title[x] = memory[0x134+x];
		std::cout << title[x];
	}
	std::cout << "\n";

	std::cout << "Console type: ";
	if(memory[0x143]=='\x80'){
		std::cout << "GameBoy Color\n";
	}else{
		std::cout << "Standard GameBoy\n";
	}

	std::cout << "Cartridge type: ";
	switch(memory[0x0147]){
		case '\x00':
			std::cout << "ROM-ONLY\n";
			break;
		case '\x01':
			std::cout << "ROM+MBC1\n";
			break;
		case '\x02':
			std::cout << "ROM+MBC1+RAM\n";
			break;
		case '\x03':
			std::cout << "ROM+MBC1+RAM+BATT\n";
			break;
		case '\x05':
			std::cout << "ROM+MBC2\n";
			break;
		case '\x06':
			std::cout << "ROM+MBC2+BATT\n";
			break;
		case '\x08':
			std::cout << "ROM+RAM\n";
			break;
		case '\x09':
			std::cout << "ROM+RAM+BATT\n";
			break;
		case '\x0b':
			std::cout << "ROM+MMM01\n";
			break;
		case '\x0c':
			std::cout << "ROM+MMM01+SRAM\n";
			break;
		case '\x0d':
			std::cout << "ROM+MMM01+SRAM+BATT\n";
			break;
		case '\x12':
			std::cout << "ROM+MBC3+RAM\n";
			break;
		case '\x13':
			std::cout << "ROM+MBC3+RAM+BATT\n";
			break;
		case '\x19':
			std::cout << "ROM+MBC5\n";
			break;
		case '\x1a':
			std::cout << "ROM+MBC5+RAM\n";
			break;
		case '\x1b':
			std::cout << "ROM+MBC5+RAM+BATT\n";
			break;
		case '\x1c':
			std::cout << "ROM+MBC5+RUMBLE\n";
			break;
		case '\x1d':
			std::cout << "ROM+MBC5+RUMBLE+SRAM\n";
			break;
		case '\x1e':
			std::cout << "ROM+MBC5+RUMBLE+SRAM+BATT\n";
			break;
		case '\x1f':
			std::cout << "Pocket Camera\n";
			break;
		case '\xfd':
			std::cout << "Bandai TAMA5\n";
			break;
		case '\xfe':
			std::cout << "Hudson HuC-3\n";
			break;
		case '\xff':
			std::cout << "Hudson HuC-1\n";
			break;
		case '\x0f':
			std::cout << "ROM+MBC3+TIMER+BATT\n";
			break;
		case '\x10':
			std::cout << "ROM+MBC3+TIMER+RAM+BATT\n";
			break;
		case '\x11':
			std::cout << "ROM+MBC3\n";
			break;
		default:
			std::cout << "[ERROR] Unknown\n";
	}

	std::cout << "ROM size: ";
	switch(memory[0x0148]){
		case '\x00':
			std::cout << "256Kbit (32Kbyte)\n";
			break;
		case '\x01':
			std::cout << "512Kbit (64Kbyte)\n";
			break;
		case '\x02':
			std::cout << "1Mbit (128Kbyte)\n";
			break;
		case '\x03':
			std::cout << "2Mbit (256Kbyte)\n";
			break;
		case '\x04':
			std::cout << "4Mbit (512Mbyte)\n";
			break;
		case '\x05':
			std::cout << "8Mbit (1Mbyte)\n";
			break;
		case '\x06':
			std::cout << "16Mbit (2Mbyte)\n";
			break;
		case '\x52':
			std::cout << "9Mbit (1.1Mbyte)\n";
			break;
		case '\x53':
			std::cout << "10Mbit (1.2Mbyte)\n";
			break;
		case '\x54':
			std::cout << "12Mbit (1.5Mbyte)\n";
			break;
		default:
			std::cout << "[ERROR] Unknown\n";
	}

	std::cout << "RAM size: ";
	switch(memory[0x0149]){
		case '\x00':
			std::cout << "No RAM\n";
			break;
		case '\x01':
			std::cout << "16kbit (2Kbyte)\n";
			break;
		case '\x02':
			std::cout << "64kbit (8Kbyte)\n";
			break;
		case '\x03':
			std::cout << "256kbit (32Kbyte)\n";
			break;
		case '\x04':
			std::cout << "1Mbit (128Kbyte)\n";
			break;
		default:
			std::cout << "[ERROR] Unknown\n";
	}

	std::cout << "Destination code: ";
	switch(memory[0x014A]){
		case '\x00':
			std::cout << "Japanese\n";
			break;
		case '\x01':
			std::cout << "Non-japanese\n";
			break;
		default:
			std::cout << "[ERROR] Unknown\n";
	}

	std::cout << "Disassemble:\n"; // page 65
	int point = 0x0100;
	while(point<65536){
		std::cout << std::hex << std::setfill('0') << std::setw(4) << point << ": ";
		switch(memory[point]){
			case '\x06':
				std::cout << "LD B, " << std::hex << std::setfill('0') << std::setw(2) << d3s::bintoint(memory[point+1]) << '\n';
				point = point + 2;
				break;
			case '\x0e':
				std::cout << "LD C, " << std::hex << std::setfill('0') << std::setw(2) << d3s::bintoint(memory[point+1]) << '\n';
				point = point + 2;
				break;
			case '\x16':
				std::cout << "LD D, " << std::hex << std::setfill('0') << std::setw(2) << d3s::bintoint(memory[point+1]) << '\n';
				point = point + 2;
				break;
			default:
				std::cout << '\n';
				point++;
		}
	}
	for(int x = 0; x<65536; x = x+16){
		//std::cout << memory[x] << memory[x+1] << memory[x+2] << memory[x+3] << memory[x+4] << memory[x+5] << memory[x+6] << memory[x+7] << memory[x+8] << memory[x+9] << memory[x+10] << memory[x+11] << memory[x+12] << memory[x+13] << memory[x+14] << memory[x+15];
	}

	return 0;
}
