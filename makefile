all: main

main: main.o
	gcc -o main main.o -Wall -pedantic -std=c99

run:
	@ ./main