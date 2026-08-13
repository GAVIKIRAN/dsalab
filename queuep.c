#include<stdio.h>
#define size 100
int queue[size];
int front=-1;
int rear=-1;

void insert(int value){
    if(rear=size-1){
        printf("queue is overflow");
    }
    if(front=-1){
        front=0;
    }
    rear++;
    queue[rear]=value;
    printf("%d element is inserted",value);
}

void delete(){
    if(front=-1 || front<rear){
        printf("Queue underflow");
    }
    printf("%d deleted ",queue[front]);
    front++;
    if(front>rear){
        front=-1;
        rear=-1;
    }
}