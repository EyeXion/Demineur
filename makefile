all : demineur

default : demineur

clean : 
	rm -f *.o exe

demineur : demineur.o demilib.o
	gcc -Wall demineur.o demilib.o -o exe

%.o : %.c 
	gcc -Wall -c $<

demineur.c : struct_demi.h
demilib.c : struct_demi.h