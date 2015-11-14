#CHEICK BERTHE
all: postfixcalc

postfixcalc: main.o Calculator.o
	gcc main.o Calculator.o -o postfixcalc.o

main.o: main.c
	gcc -c main.c

Calculator.o: Calculator.c Calculator.h
	gcc -c Calculator.c Calculator.h

clean:
	rm *o
