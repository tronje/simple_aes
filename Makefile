.PHONY: default object clean cleanup test lib

# constants
## compiler; gcc is pretty good, right?
CC = gcc

## compilation flags that should always be used
CFLAGS = -Wall -Wextra -Werror -Wshadow -Wstrict-overflow -Wpedantic

## compilation flags for debugging
DBFLAGS = -g -Og

## compilation flags with optimizations turned on
OPTFLAGS = -march=native -Os -flto

## name of our library
LIB = simple_aes.so

## object files
OBJ = simple_aes.o main.o

## object files required to run tests
TEST_OBJ = simple_aes.o test.o

## our executable
EXECUTABLE = simple_aes.x

## test executable
TEST_EXE = test.x

## most relevant files
FILES = simple_aes.c simple_aes.h

# per default, compile executable
default: $(EXECUTABLE)

# compile shared object file (library)
lib: $(FILES)
	$(CC) -shared -Os -flto -fPIC -o $(LIB) simple_aes.c

# compile an object file to use in a project
object: CFLAGS += $(OPTFLAGS)
object: $(FILES)
	$(CC) $(CFLAGS) -c simple_aes.c -o simple_aes.o

# compile executable file
$(EXECUTABLE): CFLAGS += $(OPTFLAGS)
$(EXECUTABLE): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXECUTABLE)

# run tests
test: CFLAGS += $(DBFLAGS)
test: $(TEST_EXE)
	./$(TEST_EXE)

# compile test executable; enhance debugging experience
$(TEST_EXE): $(TEST_OBJ)
	$(CC) $(CFLAGS) $(TEST_OBJ) -o $(TEST_EXE)

# compile object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# clean binary files
clean:
	rm -f *.o *.x *.so
