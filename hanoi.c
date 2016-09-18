#include <stdio.h>

#include <stdlib.h>

#define FROM  TO  USE 1

#define MAXELEMENTS 10

typedef struct {

       int A[MAXELEMENTS];

       int top;

       char name;

       }STACK;
 

void initStack(STACK *S);

int pop(STACK *S);

void push(STACK *S, int x);

void hanoi(int n, STACK* from, STACK* to, STACK* use);

void printStack(STACK S);
 

STACK S1,S2,S3;

int main (int argc, char **argv){

  int n=1;

  

  S1.name='A';S2.name='B';S3.name='C';

  initStack(&S1);printStack(S1);

  initStack(&S2);printStack(S2);

  initStack(&S3);printStack(S3);

  

  hanoi(n, &S1, &S3, &S2);

  

  getchar();

  return 0;
 

}

void hanoi(int n, STACK* from, STACK* to, STACK* use){
 

     int x;

     if(n==1)

    {

        //printf("\n%c --> %c",from->name,to->name);

        x=pop(from);push(to,x);

        printStack(S1);printStack(S2);printStack(S3);printf("\n");

        return;

    }

  if (n > 0) {

    hanoi(n-1, from, use, to);

    //printf ("\n%c --> %c", from->name,to->name);

    x=pop(from);push(to,x);

    printStack(S1);printStack(S2);printStack(S3);printf("\n");

    hanoi(n-1, use, to, from);

  }

}

void printStack(STACK S){

     int i;

     printf("\n%c:",S.name);

     for(i=0;i<=S.top;i++) printf("%d ",S.A[i]);

}

     

void initStack(STACK *S){

     int i;

     S->top=-1;

     for(i=0; i<MAXELEMENTS; i++)

              S->A[i]=i+1;

}

int pop(STACK *S){

    int element;

    if (S->top==-1) return 0;

    

    element=S->A[S->top];

    S->top--;

    return element;

}

void push(STACK *S, int x){

     

     if (S->top==MAXELEMENTS-1) {printf("\full stack!");return;}

     

     S->top++;

     S->A[S->top] = x;

}
