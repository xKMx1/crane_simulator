all: complie link

complie:
	g++ -Isrc/include -c main.cpp

link:
	g++ main.o -o CraneSimulator -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system