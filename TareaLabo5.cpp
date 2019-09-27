
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: JoseG23
 *
 * Created on 26 de septiembre de 2019, 07:03 PM
 */

#include<stdio.h>
#include<stdlib.h>
#include <iostream>
using namespace std;

struct node
{
    int key;
    struct node *der, *izq;
};

struct node *newNode(int e) //element
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->key=e;
    temp->der=temp->izq=NULL;
    return temp;
}

struct node* insert(struct node* node, int key)
{
    if (node==NULL) return newNode(key);
    
    if (key<node->key)
        node->der=insert(node->der, key);
    else if (key>node->key)
        node->izq=insert(node->izq, key);
    
    return node;
}

void postOrder(struct node* node){ //Funcion postOrder
    if (node==NULL)
        return;
    
    postOrder(node->der);
    postOrder(node->izq);
    cout<<node->key<< " ";
}

int main()
{
    struct node *root=NULL;
    root=insert(root, 8);
    insert(root, 3);
    insert(root, 10);
    insert(root, 1);
    insert(root, 6);

    //PRINT POST-ORDER
    printf("Post-Order: \n");
    postOrder(root);
    
    return 0;
}