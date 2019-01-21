CC=	clang
CFLAGS=	-Weverything -g

all: system_calls_test
clean:
	rm -f  system_calls_test *.o

system_calls_test: main.o
	$(CC) main.o -o system_calls_test
