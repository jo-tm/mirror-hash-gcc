CC = gcc
CFLAGS = -Wall -O3

all: mirror256_test

mirror256_test: main.o mirror256.o
	$(CC) $(CFLAGS) -o mirror256_test main.o mirror256.o

main.o: main.c mirror256.h
	$(CC) $(CFLAGS) -c main.c

mirror256.o: mirror256.c mirror256.h
	$(CC) $(CFLAGS) -c mirror256.c

clean:
	rm -f *.o mirror256_test
