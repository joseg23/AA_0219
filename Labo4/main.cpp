/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: JoseG23
 *
 * Created on 18 de septiembre de 2019, 09:53 PM
 */

#include <bits/stdc++.h>
using namespace std;

void swap(int*x, int*y)
{
    int z=*x;
    *x=*y;
    *y=z;
}

int particion(int arr[], int down, int top)
{
    int pivot=arr[top];
    int i=(down-1); 
    for (int j=down; j<=top-1; j++)
    {
        if (arr[j]<pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[top]);
    return (i+1);
}

int main(int argc, char** argv) {

    return 0;
}

