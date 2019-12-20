/*
 * Node.h
 *
 *  Created on: 28 Eki 2019
 *      Author: Erten
 */

#ifndef NODE_H_
#define NODE_H_

struct node {
	int data;
	struct node *left;
	struct node *right;
};

typedef struct node Node;

Node* createNode(int value);
Node* insert(Node* root, int data);
Node* minValueNode(Node* node);
Node* deleteNode(Node* root, int data);

void inorder(Node *root);
int  search(Node* root, int data);

#endif /* NODE_H_ */
