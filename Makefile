all:PhotoMagic
PhotoMagic: PhotoMagic.o FibLFSR.o 
	g++ PhotoMagic.o FibLFSR.o -o PhotoMagic -lsfml-graphics -lsfml-window -lsfml-system
PhotoMagic.o: PhotoMagic.cpp
	g++ -c PhotoMagic.cpp
FibLFSR.o: FibLFSR.cpp FibLFSR.h
	g++ -c FibLFSR.cpp
clean:
	rm *.o PhotoMagic
