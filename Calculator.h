#ifndef CALCULATOR_H_INCLUDED
#define CALCULATOR_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>

typedef int StackType;

typedef struct Stack{
    StackType data;
    struct Stack* next;
} Stack;

void push(StackType item , Stack* aStack);
StackType pop(Stack* aStack);
unsigned int stackSize(Stack* aStack);
void print(Stack* aStack);
StackType peek(Stack* aStack);
void emptyStack(Stack* aStack);
#endif // CALCULATOR_H_INCLUDED
