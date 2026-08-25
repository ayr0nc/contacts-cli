all: contacts
save_load.o: save_load.c save_load.h operations.h contact.h 
	gcc -c save_load.c 

operations.o: operations.c operations.h save_load.h contact.h
	gcc -c operations.c 

main.o: operations.h main.c save_load.h contact.h 
	gcc -c main.c 

contacts: save_load.o operations.o main.o 
	gcc save_load.o operations.o main.o -o contacts
