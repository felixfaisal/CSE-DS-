#include<stdio.h>
#include <stdlib.h>
struct location{
  int item;
  struct location * address;
};
typedef struct location* lct;
lct first = NULL;
lct create()
{
  lct node;
  node=(lct)malloc(sizeof(struct location));
  return(node);
}
lct insert(lct first,int item)
{
  lct temp;
  temp=create();
  temp->item=item;
  temp->address=NULL;
  if(first!=NULL)
    temp->address=first;

  first=temp;
  return(first);
}
void display(lct first)
{
  if(first==NULL)
    printf("No elements in the list\n");
  else{
    lct cur;
    cur=first;
    printf("Elements in the list are:\n");
    while(cur!=NULL){
      printf("%d\n",cur->item);
      cur=cur->address;
    }
  }
}
lct deletepos(lct first,int pos){
  lct cur,prev;
  cur=first;
  if(first==NULL){
    printf("List is empty\n");
    return(first);
  }
  if(pos==1){
    first=first->address;
    printf("The deleted item is %d\n",cur->item);
    free(cur);
    return(first);
  }
  for(int i=0;i<pos-1;i++){
    prev=cur;
    cur=cur->address;
  }
  printf("Deleting item=%d\n",cur->item);
  prev->address=cur->address;
  free(cur);
  return(first);
}
lct dfirst(lct first){
  if(first==NULL){
    printf("List is empty\n");
    return(first);
  }
  lct cur;
  cur=first;
  printf("The deleted item is %d\n",cur->item);
  first=first->address;
  free(cur);
  return(first);
}
lct dlast(lct first){
  if(first==NULL){printf("list is empty\n");return(first);}
  /*else if(first->address=NULL){
    printf("The deleted first item is %d\n",first->item);
    lct cur;
    cur=first;
    first=first->address;
    free(cur);
    return(first);
}*/
  lct cur,prev;
  cur=first;
  while(cur->address!=NULL){
    prev=cur;
    cur=cur->address;
  }
  printf("The deleted item is %d\n",cur->item);
  if(cur==first){
    first=NULL;
    return(first);
  }
  prev->address=NULL;
  free(cur);
  return(first);

}
void main()
{
  int choice,item;
  for(;;)
  {
    printf("1.Insert\n2.Display\n3.Delete Position\n4.Delete First\n5.Delete Last\n6.Exit\nEnter choice:");
    scanf("%d",&choice);
    switch (choice) {
      case 1:printf("Enter value to be inserted\n");
      scanf("%d",&item);
      first=insert(first,item);
      break;
      case 2: display(first);
      break;
      case 3:printf("Enter position to be deleted\n");
      scanf("%d",&item);
      first=deletepos(first,item);
      break;
      case 4:first=dfirst(first);
      break;
      case 5:first=dlast(first);
      break;
      default: exit(0);
    }
  }
}
