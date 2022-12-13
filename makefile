main: main.o utils.o
	gcc -Wall -O0 -o main.out main.o utils.o

time: time.o utils.o
	gcc -Wall -O0 -o time.out time.o utils.o

space: space.o utils.o
	gcc -Wall -O0 -o space.out space.o utils.o

main.o:
	gcc -o main.o -c main_test.c

utils.o: 
	gcc -o utils.o -c utils/utils.c

time.o: 
	gcc -o time.o -c main_b_time.c

space.o: 
	gcc -o space.o -c main_b_space.c


	

clear:
	rm -f *.o
	rm -f *.out
	rm -f *.dat