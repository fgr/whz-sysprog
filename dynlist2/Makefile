CC=clang
CFLAGS=-std=c99 -fPIC -Wall -pedantic-errors -I./list

listtest: main.o
	$(CC) -o listtest ./list/liblist.so.1 $<

clean:
	rm -f main.o

distclean: clean
	rm -f listtest
