CC 	 = gcc
CFLAGS = -Wall -std=c99 -pedantic -g
OFLAGS = -Wall -pedantic -g
E_OBJS = pencode.o imgparse.o safe.o
D_OBJS = pencode.o imgparse.o safe.o

all : pencode pdecode

pencode : $(E_OBJS) pencode.c pencode.h
	$(CC) $(OFLAGS) $(E_OBJS) -o pencode

pdecode : $(D_OBJS) pdecode.c pdecode.h
	$(CC) $(OFLAGS) $(D_OBJS) -o pdecode

pencode.o : pencode.c pencode.h
	$(CC) $(CFLAGS) -c pencode.c

pdecode.o : pdecode.c pdecode.h
	$(CC) $(CFLAGS) -c pdecode.c

imgparse.o : imgparse.c imgparse.h
	$(CC) $(CFLAGS) -c imgparse.c

safe.o : safe.c safe.h
	$(CC) $(CFLAGS) -c safe.c

clean :
	rm *.o $(MAIN) 

# test:	$(MAIN)
# 	./httpd