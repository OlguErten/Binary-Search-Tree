/*
 * Stack.h
 *
 *  Created on: 28 Eki 2019
 *      Author: Erten
 */

#ifndef STACK_H_
#define STACK_H_

struct stack {
	int top;
	int capacity;
	int* task;
	int* values;
};

typedef struct stack Stack;

Stack* createStack(int capacity);
int isFull(Stack* stack);
int isEmpty(Stack* stack);
void push(Stack* stack, int t, int item);
int pop(Stack* stack);

#endif /* STACK_H_ */
