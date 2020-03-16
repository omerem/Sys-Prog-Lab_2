all: do

do: menu_map.o
	gcc -g -Wall -o do menu_map.o

menu_map.o: menu_map.c
	gcc -g -Wall -c -o menu_map.o menu_map.c


.PHONY: clean

clean: 
	rm -f *.o do
