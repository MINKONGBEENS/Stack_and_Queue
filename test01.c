#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 6
typedef int element;

typedef struct 
{
    int top;
    int stack[MAX_STACK_SIZE];

}StackType;



void init_stack(StackType *s){
    s->top = -1;
}

int is_empty(StackType *s) {
    return s->top == -1;
}

int is_full(StackType *s) {
    return s->top == (MAX_STACK_SIZE - 1);
}

void push(StackType *s, element item) {

    if(is_full(s)){
        fprintf(stderr,"스택 포화 에러\n");
        return;
    }

    else s->stack[++(s->top)] = item;
    
}

int pop(StackType *s) {

    if(is_empty(s)){
        fprintf(stderr,"스택 공백 에러\n");
        exit(1);
    }

    else return s->stack[(s->top)--];
}

int peek(StackType *s) {

     if(is_empty(s)){
        fprintf(stderr,"스택 공백 에러\n");
        exit(1);
    }

    else return s->stack[s->top];
}

