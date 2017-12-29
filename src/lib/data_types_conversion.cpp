#include "data_types_conversion.h"
namespace d3s{
	int bintoint(char data){
		switch(data){
			case '\x00':
				return 0;
				break;
			case '\x01':
				return 1;
				break;
			case '\x02':
				return 2;
				break;
			case '\x03':
				return 3;
				break;
			case '\x04':
				return 4;
				break;
			case '\x05':
				return 5;
				break;
			case '\x06':
				return 6;
				break;
			case '\x07':
				return 7;
				break;
			case '\x08':
				return 8;
				break;
			case '\x09':
				return 9;
				break;
			case '\x0a':
				return 10;
				break;
			case '\x0b':
				return 11;
				break;
			case '\x0c':
				return 12;
				break;
			case '\x0d':
				return 13;
				break;
			case '\x0e':
				return 14;
				break;
			case '\x0f':
				return 15;
				break;
			case '\x10':
				return 16;
				break;
			case '\x11':
				return 17;
				break;
			case '\x12':
				return 18;
				break;
			case '\x13':
				return 19;
				break;
			case '\x14':
				return 20;
				break;
			case '\x15':
				return 21;
				break;
			case '\x16':
				return 22;
				break;
			case '\x17':
				return 23;
				break;
			case '\x18':
				return 24;
				break;
			case '\x19':
				return 25;
				break;
			case '\x1a':
				return 26;
				break;
			case '\x1b':
				return 27;
				break;
			case '\x1c':
				return 28;
				break;
			case '\x1d':
				return 29;
				break;
			case '\x1e':
				return 30;
				break;
			case '\x1f':
				return 31;
				break;
			case '\x20':
				return 32;
				break;
			case '\x21':
				return 33;
				break;
			case '\x22':
				return 34;
				break;
			case '\x23':
				return 35;
				break;
			case '\x24':
				return 36;
				break;
			case '\x25':
				return 37;
				break;
			case '\x26':
				return 38;
				break;
			case '\x27':
				return 39;
				break;
			case '\x28':
				return 40;
				break;
			case '\x29':
				return 41;
				break;
			case '\x2a':
				return 42;
				break;
			case '\x2b':
				return 43;
				break;
			case '\x2c':
				return 44;
				break;
			case '\x2d':
				return 45;
				break;
			case '\x2e':
				return 46;
				break;
			case '\x2f':
				return 47;
				break;
			case '\x30':
				return 48;
				break;
			default:
				return 0;
		}
	}
}
