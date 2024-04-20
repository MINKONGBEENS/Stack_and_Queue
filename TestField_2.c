#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
typedef int element;
typedef struct 
{
    element stack[MAX_STACK_SIZE];
    int top;

}StackType;

typedef struct 
{
    int my_int;
    char my_char;
    double my_double;

}StackData;


void init_stack(StackType *s) {
    s -> top = -1;
}

int is_empty(StackType *s) {
    return s -> top == -1;
}

int is_full(StackType *s) {
    return s -> top == (MAX_STACK_SIZE - 1);
}

void push()