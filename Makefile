CC=g++
gd-disasmmake: ./src/main.cpp ./src/lib/data_types_conversion.cpp
	$(CC) -o ./bin/gb-disasm ./src/main.cpp ./src/lib/data_types_conversion.cpp
