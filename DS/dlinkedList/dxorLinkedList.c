//sg
#include<stdio.h>
/*
 * This program implements a doubly linked list using only one 
 * pointer. It starts by storing the address of the element itself in the first
 * node.
 * For the subsequent entries, the program takes an XOR of the current address and the 
 * start value and then updates the start pointer.
 * Thus effectively, the insertions take place at the begining only.
 * The traversal is acheived as follows : 
 * moving left :
 * 	addressLeft=left^current;
 * =>	addressLeft=left^(left^right)=right;
 * similar mechanism is used to move right.
 */
typedef struct node
{
int data;
struct node * lXr;
}node;
//__________________________________
int xor(int * a ,int * b)
{
  unsigned int av,bv;
  av=a;
  bv=b;
  
return av^bv;
}
//_________________________________
void add(node ** start,node ** rear,int data)
{
node * temp=*start,*new;
new=(node *)malloc(sizeof(node));
new->data=data;
if(temp==NULL)
{
new->lXr=new; //first node will store the address of itself
*start=new;
*rear=new;
return;
}
//all the subsequent nodes shall store the value *startxortheir addr
//this will create the list of the form :
//first -> |firstxorC|->|CxorB|->|BxorA|->|A}
//assuming A was the first element to be inserted
new->lXr=xor(*start,new); //for any new number,store lxorr;
*start=new;

}
void printLR(node * start)
{
while(start)
{
printf("%d-",start->data);
start=xor(start,(start->lXr));
}
printf("\n");
}
void printRL(node * rear)
{
while(rear)
{
printf("%d-",rear->data);
rear=xor((rear->lXr),rear);
}
printf("\n");
}
main()
{
node * start=NULL,*rear=NULL;
add(&start,&rear,4);
add(&start,&rear,5);
printLR(start);
printRL(rear);
/*
print(rear);
*/
}
