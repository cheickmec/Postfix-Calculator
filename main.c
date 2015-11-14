

#include "Calculator.h"
#include <string.h>
#include <stdio.h>
int main(int argc , char** argv)
{
    char operation[100] ;
    char* segment;
    int nbytes = 100;
    printf("please enter a postfix operation\n");
    fgets(operation,nbytes,stdin);
    if(strlen(operation) <=0){
        printf("You haven't entered any operation\n");
        return 0;
    }

    Stack* mystack = (Stack*)malloc(sizeof(Stack));
    segment = strtok(operation," ");
    int result = 0;
    while(segment!=NULL){
       //printf("value %s: ",segment);
        if(strcmp(segment,"+")==0){
            result = pop(mystack) + pop(mystack);
            push(result,mystack);
         //   printf("adding\n");
        }
        else if(strcmp(segment,"-")==0){
            result = pop(mystack);
            result = pop(mystack) - result;;
            push(result,mystack);
           // printf("subtracting\n");
            }
        else if(strcmp(segment,"*")==0){
            result = pop(mystack) * pop(mystack);
            push(result,mystack);
            //printf("multiplying\n");
        }
        else if(strcmp(segment,"/")==0){
            result = pop(mystack);
            result = pop(mystack) / result;
            push(result,mystack);
            //printf("dividing\n");
        }
        else{
            //printf("pushing %s\n",segment);
            push((StackType)atoi(segment),mystack);
        }
        segment = strtok(NULL," \n");
    }
    if(stackSize(mystack) > 1){
        printf("You have provided too many inputs\n");
        exit(1);
    }
    printf("The answer is: %d\n",pop(mystack));

    emptyStack(mystack);
    return 0;
}
