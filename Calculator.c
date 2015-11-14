#include "Calculator.h"

void push(StackType item , Stack* aStack){
    Stack* newNode = (Stack*) malloc(sizeof(Stack));
    if(newNode == 0){
    printf("cannot allocate memory\n");
    exit(1);
    }
    newNode->data = item;
    if(aStack->next == 0){
        aStack->next = newNode;
        newNode->next = 0;
    }
    else{
        newNode->next = aStack->next;
        aStack->next = newNode;
    }
}
StackType pop(Stack* aStack){
    if(aStack->next == 0){
        printf("not enough input\n");
        exit(1);
    }
    Stack* toPop = aStack->next;
    aStack->next = toPop->next;
    StackType item = toPop->data;
    toPop->next = 0;
    free(toPop);
    return item;
}
unsigned int stackSize(Stack* aStack){
    if(aStack->next == 0) return 0;
    unsigned int count = 1;
    Stack* it = aStack->next;
    while(it->next != 0){
        ++count;
        it = it->next;
    }
    return count;
}
void print(Stack* aStack){
    if(aStack->next == 0){
        printf("empty stack\n");
        return;
    }
    Stack* pStack = aStack;
    while(pStack->next!=0){
        pStack = pStack->next;
        printf("element: %d\n",pStack->data);

    }
}
StackType peek(Stack* aStack){
    if(aStack->next == 0)
    {
        printf("cannot peek in empty stack\n");
        exit(1);
    }
    return aStack->next->data;
}
void emptyStack(Stack* aStack){
    while(aStack->next != 0){
        pop(aStack);
    }
    free(aStack);
}
