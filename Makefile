output: main.o hash.o link.o
	gcc -o output main.o hash.o link.o

main.o: main.c hash.h
	gcc -c main.c

hash.o: hash.c link.h
	gcc -c hash.c

link.o: link.h
	gcc -c link.c

clear:
	rm *.o output
