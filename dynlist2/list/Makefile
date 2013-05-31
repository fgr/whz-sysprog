CFLAGS=-std=c99 -fPIC
LIBVERSION=1

# Object files comprising the list lib
OBJECTS=$(patsubst %.c,%.o,$(wildcard *.c))

####################################

.PHONY: all 
all: dynliblist staticliblist 

dynliblist: $(OBJECTS)
	gcc -shared -Wl,-soname,liblist.so.$(LIBVERSION) -o liblist.so.$(LIBVERSION).0.0 $?
	ln -s liblist.so.$(LIBVERSION).0.0 liblist.so.1

staticliblist: $(OBJECTS)
	ar rcs liblist.a $?

.PHONY: clean
clean:
	rm -f $(OBJECTS) 

.PHONY: distclean
distclean: clean
	rm -f *.a *.so.*
