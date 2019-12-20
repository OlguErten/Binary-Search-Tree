/*
 * Stack.c
 *
 *  Created on: 29 Eki 2019
 *      Author: Erten
 */

#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"


/* Stack initializer */
Stack* createStack(int capacity)
{
	Stack *stack_ptr = (Stack*)malloc(sizeof(Stack));

	stack_ptr->capacity = capacity;
	stack_ptr->top = -1;
	stack_ptr->values = (int*)malloc(sizeof(int) * capacity);

	return stack_ptr;
}

/* Function to check if the stack is empty or not */
int isEmpty(Stack *stack)
{
	return stack->top == -1;
}

/* Utility function to check if the stack is full or not */
int isFull(Stack *stack)
{
	return stack->top == stack->capacity - 1;
}

/* Utility function to add an element x in the stack */
void push(Stack *stack, int t, int item)
{
	/* Check before inserting element if stack full or not to prevent stack overflow */
	if (isFull(stack))
	{
		exit(1);
	}

	/* Insert the task */
	stack->task = t;
	/* Add the elemet and increase the stack pointer */
	stack->values[++stack->top] = item;
}

/* Utility function to pop top element from the stack */
int pop(struct stack *stack)
{
	int retVal = 0;
	/* Check if stack is empty or not */
	if (isEmpty(stack))
	{
		exit(1);
	}
	else
	{
		retVal = ((char)stack->task[stack->top])<<8;
		retVal += (char)stack->values[stack->top];

		stack->task[stack->top] = -1;
		stack->values[stack->top] = -1;
		stack->top = stack->top - 1;
	}
	return retVal;
}
