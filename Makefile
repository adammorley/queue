CC=/usr/local/Cellar/llvm/5.0.0/bin/clang
CFLAGS=-I. -g

all: test

clean:
	rm -f test *.o

test: test.c queue.c
	$(CC) -o test test.c queue.c $(CFLAGS)


