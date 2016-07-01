.PHONY: default object clean cleanup test lib
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror -Wshadow -Wstrict-overflow -Wpedantic -march=native
LIB = simple_aes.so
OBJ = simple_aes.o test.o
EXECUTABLE = test.x

default: test

lib: simple_aes.h simple_aes.c
	$(CC) -shared -O2 -fPIC -o $(LIB) simple_aes.c

object: simple_aes.h simple_aes.c
	$(CC) -O3 -march=native -c simple_aes.c -o simple_aes.o

test: test.x
#	./test.x

test.x: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXECUTABLE)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o *.x

cleanup: clean
	rm -f *.so
