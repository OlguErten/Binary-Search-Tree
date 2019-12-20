#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Node.h"
#include "Stack.h"

int main()
{

    Node *root = NULL;
    Stack *stack_ptr = NULL;
    int Size, rollback,temp_value,temp_id;
    int op[10];
    int i, j, k, l;
    int inst, del, srch;

    /* Generate 10 random tasks */                          /* Task id */
    for(i = 0; i<10; i++)                                   /* 1. Insert a value to binary search tree. */
    {                                                       /* 2. Delete a value from binary search tree. */
    	op[i] = (rand() % 4) + 1;                           /* 3. Find the minimum element in the binary search tree. */
    }                                                       /* 4. Search a value in tree with no duplicates and show how many steps the value is found. */

    root = createNode(rand() % 100);                        /* Create initial node */
    stack_ptr = createStack(15);                            /* Create initial stack for deletion */

    printf("Please enter an initial size for tree: \n");
    scanf("%d", &Size);

    srand(time(NULL));
    for (j=1; j<Size; j++)                                  /* Create a tree */
    {
    	insert(root, rand() % 100);
    }

    printf("Initialized tree is: \n");
    inorder(root);                                         /* Put it in a order */
    printf("\n");

    for (k=0; k<10; k++)
    {
    	switch(op[k])
    	{
    		case 1:
    			inst = rand() % 100;
    			insert(root, inst);
				printf("Element %d inserted. \n", inst);
				printf("Tree is updated to: \n");
    			inorder(root);
    		    printf("\n");
    		    push(stack_ptr, op[k], inst);
    			break;
    		case 2:
		        del = rand() % 100;
    			deleteNode(root, del);
    			if(0 != search(root, del))
    			{
    				printf("Element %d deleted. \n", del);
    				printf("Tree is updated to: \n");
    				inorder(root);
    				printf("\n");
    				push(stack_ptr, op[k], del);
    			}

    			else
    			{
    				printf("Element %d is not in the tree \n" ,del);
    			}
    			break;
    		case 3:
    			minValueNode(root);
    			break;
    		case 4:
				srch = rand() % 100;
				if(0 != search(root, srch))
    			{
    				search(root, srch);
					printf("\nSearched element %d is found. \n", srch);
				}
				else
					printf("\nSearched element %d can't found in tree. \n", srch);
    			break;
    		default:
    			printf("Invalid operation. Exiting!");
    			exit(1);
    	}
    }

    printf("Please enter the roll-back count: \n");
    scanf("%d", &rollback);

	for(l = 0; l< rollback; l++)
	{
		int temp = pop(stack_ptr);
		temp_value = (char)temp;
		temp_id = (char)(temp>>8);
		if(temp_id == 1)
		{
			printf("inserted value %d deleted \n",temp_value);
			deleteNode(root, temp_value);
			inorder(root);
			printf("\n");
		}
		else
		{
			printf("deleted value %d inserted \n",temp_value);
			insert(root, temp_value);
			inorder(root);
			printf("\n");
		}

	}

    return 0;
}
