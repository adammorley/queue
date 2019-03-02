CC=clang
CFLAGS=-I. -g
DEPS=../log/log.c

all: test

clean:
	rm -f test *.o

test: test.c queue.c $(DEPS)
	$(CC) -o test test.c queue.c $(DEPS) $(CFLAGS)


