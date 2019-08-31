/* 
 * File:   main.cpp
 * Author: JoseG23
 * Carnet: 00051716
 * Created on 30 de agosto de 2019, 05:08 PM
 */

#include <iostream>

using namespace std;

//Si no te corre en Neatbeans lo podes probar en C++ Shell.

struct Node{
    int data;
    Node *next;
}*star;

class Stack{
public:
    Node* createNode(int value){
        Node *n=new Node;
        n->data=value;
        n->next= nullptr;
        return n;
    }
         
    void pop(){
        Node *temp=star;
        star=star->next;
        free(temp);
    }
    
    void push(int value){
        Node *n=createNode(value);
        n->next=star;
        star=n;
    }

    void showStack(){
        Node *temp=star;
        if(!star)
            cout<<"Empty Stack"<<endl;
        else
            while (temp) {
                cout<< temp->data<<" ";
                temp=temp->next;
            }
    }
};

void array(){
    int i,odd=0,even=0;
    int A[]={122,20,83,14,55,68}; //IMGRESAR DATOS A SU ANTOJO
    int size=*(&A + 1) - A;
    Stack stack;
    
    for(i=0; i<size; i++){
        if(A[i]%2==0)
        {
            even++;
            stack.push(A[i]);
        }
        else{
            odd++;
            stack.push(A[i]);
        }
    }
    
    cout<<"Pila: "<<endl;
    stack.showStack();
    
    cout<<"\n\nTotal pares: "<<even<<endl;
    cout<<"Total impares: "<<odd<<endl;
    
    if(even==odd)
        cout<<"\nSon pilas iguales"<<endl;
    else
        cout<<"\nSon pilas distintas"<<endl;
}
 
int main(){
    array();
    return 0;
}

