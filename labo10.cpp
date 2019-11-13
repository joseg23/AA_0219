#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct node
{
    int key;
    struct node *der, *izq;
    int altura;
};

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int altura(node *N)
{
    if (N == NULL)
        return 0;
    return N->altura;
}

struct node *newNode(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->der = temp->izq = NULL;
    temp->altura = 1;
    return temp;
}

/*void preOrder(struct node *root)
{
    if (root == NULL)
        return;

    printf("%d ", root->key);
    preOrder(root->der);
    preOrder(root->izq);
}*/

void inOrder(struct node *root)
{
    if (root != NULL)
    {
        inOrder(root->der);
        printf("%d \n", root->key);
        inOrder(root->izq);
    }
}

int getBalance(node *N)
{
    if (N == NULL)
        return 0;
    return altura(N->der) - altura(N->izq);
}

node *izqRotate(node *y)
{
    node *x = y->der;
    node *T2 = x->izq;

    x->izq = y;
    y->der = T2;

    y->altura = max(altura(y->der), altura(y->izq)) + 1;
    x->altura = max(altura(x->der), altura(x->izq)) + 1;

    return x;
}

node *derRotate(node *x)
{
    node *y = x->izq;
    node *T2 = y->der;

    y->der = x;
    x->izq = T2;

    x->altura = max(altura(x->der), altura(x->izq)) + 1;
    y->altura = max(altura(y->der), altura(y->izq)) + 1;

    return y;
}

struct node *insert(struct node *node, int key)
{
    if (node == NULL)
        return newNode(key);

    if (key < node->key)
        node->der = insert(node->der, key);
    else if (key > node->key)
        node->izq = insert(node->izq, key);

    node->altura = 1 + max(altura(node->der),
                           altura(node->izq));

    int balance = getBalance(node);

    if (balance > 1 && key < node->der->key)
        return izqRotate(node);

    if (balance < -1 && key > node->izq->key)
        return derRotate(node);

    if (balance > 1 && key > node->der->key)
    {
        node->der = derRotate(node->der);
        return izqRotate(node);
    }

    if (balance < -1 && key < node->izq->key)
    {
        node->izq = izqRotate(node->izq);
        return derRotate(node);
    }

    return node;
}

int main()
{
    struct node *root = NULL;

    // newNode(10);
    // root->izq = newNode(12);
    // root->izq->izq = newNode(15);
    // root->der = newNode(8);
    // root->der->izq = newNode(9);
    // root->der->der = newNode(7);
    // root->der->der->der = newNode(6);
    // root->der->der->der->der = newNode(3);
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 7);
    root = insert(root, 8);

    cout << "In Order: ";
    inOrder(root);

    return 0;
}



