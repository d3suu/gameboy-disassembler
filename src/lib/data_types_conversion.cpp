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
			default:
				return 0;
		}
	}
}
