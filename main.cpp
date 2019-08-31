/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: JoseG23
 * 00051716
 * Created on 30 de agosto de 2019, 05:08 PM
 */


#include <iostream>
#include <string>
using namespace std;

struct Node{
    int data;
    Nodo *next;
}*begin;

class Stack{
public:
    Node* createNode(int value){
        Node *n=new Node;
        n->data=value;
        n->next= nullptr;
        return n;
    }
    
    void push(int value){
        Node *n=crearNodo(value);
        n->next=begin;
        begin=n;
    }
    
    void pop(){
        Nodo *temp=begin;
        begin=begin->next;
        free(temp);
    }
    
    void showStack(){
        Nodo *temp=begin;
        if(!begin)
            cout<<"Empty Stack" << endl;
        else
            while (temp) {
                cout<< temp->data << ",";
                temp=temp->next;
            }
    }
    
    Stack(){
        begin=nullptr;
    }
};


