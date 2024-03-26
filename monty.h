#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stdio.h>

/* Data structure for stack */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/* Data structure for instructions */
typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Prototypes */
void push(stack_t **stack, int value);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */