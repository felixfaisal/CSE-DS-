#include<stdio.h>
#include<stdlib.h>
struct stack
{
  int item;
  struct stack* next;
};
typedef struct stack* stk;
stk top=null;
stk create()
{
  stk node;
  node=(stk)malloc(struct stack);
  return(node);
}
void push(){
  int item;
  printf("Enter the item to be pushed\n");
  scanf("%d",&item);
  stk temp=create();
  temp->item=item;
  temp->next=top;
  top=temp;
}
void pop(){
  stk temp;
  temp=top;
  top=top->next;
  free(temp);
}
void display()
{
  stk temp;
  temp=top;
  printf("The elements in the stack are\n");
  while (temp!=NULL) {
    printf("%d\n",temp->item);
    temp=temp->next;
  }
}
void main()
{
  int choice;
  for(;;){
    printf("Enter your choice\n1.Push\n2.Pop\n3.Display\n4.Exit");
    switch(choice){
      case 1: push();
      displaay();
      break;
      case 2: pop();
      dispaly();
      break;
      case 3: display();
      break;
      default:exit(0);
    }
  }
}
