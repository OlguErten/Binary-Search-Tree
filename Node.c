/*
 * Node.c
 *
 *  Created on: 29 Eki 2019
 *      Author: Erten
 */

#include <stdio.h>
#include <stdlib.h>
#include "Node.h"

/* Function for creating new node */
Node* createNode(int data)
{
    Node * new_node_ptr;

    new_node_ptr = malloc(sizeof(Node)); /* Allocate memory space much as size of node struct */

    new_node_ptr->data = data; /* Initialize the node with given element */
    new_node_ptr->left = NULL; /* Initialize left branch as NULL */
    new_node_ptr->right = NULL; /* Initialize right branch as NULL */

    return new_node_ptr;
}

/* Function for inserting new element to the node */
Node* insert(Node *root, int data)
{
    if(root==NULL) /* NULL spot found element can be inserted there */
    {
        return createNode(data);
    }
    else if(data>root->data) /* If data is greater than the root element, it should be inserted as right branch */
    {
        root->right = insert(root->right, data);
    }
    else /* If data is smaller than the root element, it should be inserted as left branch */
    {
        root->left = insert(root->left,data);
    }

    return root;
}

/* Function for finding the minimum element in a node */
Node* minValueNode(Node* root)
{
    if(root == NULL) /* If the tree is empty return NULL */
    {
    	return NULL;
    }

    else if(root->left != NULL) /* The minimum value in the tree will have no left child */
    {
    	return minValueNode(root->left); // left most element will be minimum
    }

    printf("Minimum element is %d\n", root->data);

    return root;
}

/* Function for deleting an element from the node */
Node* deleteNode(Node *root, int data)
{
    /* Searching for the element to be deleted */
    if(root==NULL)
    {
        return NULL;
    }

    if (data>root->data)
    {
        root->right = deleteNode(root->right, data);
    }

    else if(data<root->data)
    {
        root->left = deleteNode(root->left, data);
    }

    else
    {
        if(root->left==NULL && root->right==NULL)
        {
            free(root);
            return NULL;
        }

        else if(root->left==NULL || root->right==NULL)
        {
            Node *temp;
            if(root->left==NULL)
                temp = root->right;
            else
                temp = root->left;
            free(root);
            return temp;
        }

        else
        {
            Node *temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

void inorder(Node* root)
{
    if(root != NULL) /* Do a NULL check */
    {
        inorder(root->left); /* To the left branch */
        printf(" %d ", root->data); /* Print the data */
        inorder(root->right); /* To the right branch */
    }

}

/* Function for search throughout to tree */
int search(Node* root, int data)
{
	int Counter = 0;
	
	Counter++; /* Every time recursion occurs ( move inside the tree ) Counter will be increased */
	if(root == NULL)
	{
		Counter = 0; 
		return Counter;
	}
	
    if(root->data==data) /* If root is the given data then search is complete and element found */
    {
		Counter = 0; /*Element found re-initialize the counter for other search calls*/
    	return data;
    }

    else if (data>root->data) /* If given data is greater than the root element, continue to search with right tree */
    {
    	return search(root->right, data);
    }

    else /*If given data is smaller than the root element, continue to search with left tree */
    {
        return search(root->left,data);
    }
}
