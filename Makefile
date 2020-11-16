all: main

p1: main.cpp
	g++ -g main.cpp -o main

clean:
	rm -rf main
