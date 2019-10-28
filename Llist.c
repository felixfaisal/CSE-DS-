#include<stdio.h>
#include <stdlib.h>
struct location{
  int item;
  struct location * address;
};
typedef struct location* lct;
int listsize;
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
  listsize++;
  return(first);
}
lct insertpos(lct first,int item,int pos){
  if(pos>listsize){printf("No such position exists\n");return(first);}
  lct temp;
  temp=create();
  temp->item=item;
  temp->address=NULL;
  if(pos==1){
    first=temp;
    listsize++;
    return(first);
  }
  else{
    lct cur;
    cur=first;
    for(int i=0;i<pos-2;i++){
      cur=cur->address;
    }
    temp->address=cur->address;
    cur->address=temp;
    listsize++;
    return(first);
  }
}
lct insertlast(lct first,int item){
  lct temp;
  temp=create();
  temp->item=item;
  temp->address=NULL;
  if(first==NULL){first=temp;return(first);}
  lct cur;
  cur=first;
  while(cur->address!=NULL){
    cur=cur->address;
  }
  cur->address=temp;
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
  if(pos>listsize){printf("No such position exists\n");return(first);}
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
    listsize--;
    return(first);
  }
  for(int i=0;i<pos-1;i++){
    prev=cur;
    cur=cur->address;
  }
  printf("Deleting item=%d\n",cur->item);
  prev->address=cur->address;
  listsize--;
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
  listsize--;
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
  listsize--;
  free(cur);
  return(first);

}
lct reverse(lct first){
  lct cur,prev;
  prev=first;
  first=first->address;
  cur=first;
  prev->address=NULL;
  while(first!=NULL){
    first=first->address;
    cur->address=prev;
    prev=cur;
    cur=first;
  }
  printf("prev = %d\n",prev->item);
  first=prev;
  return(first);
}
lct sort(lct first){
  for(lct i=first;i->address!=NULL;i=i->address){
    for(lct j=i->address;j!=NULL;j=j->address){
      if(i->item>j->item){
        int temp;
        temp=i->item;
        i->item=j->item;
        j->item=temp;
      }
    }
  }
  return(first);
}
lct removeo(lct first){
  lct cur;
  lct trash;
  lct prev;
  cur=first->address;
  if(cur->address==NULL || first==NULL){printf("Cannot perform this operation"); return(first);}
  while(cur!=NULL){
    for(int i=0;i<1;i++){
      prev=cur;
      cur=cur->address;
    }
    printf("Deleting %d\n",cur->item);
    prev->address=cur->address;
    trash=cur;
    cur=cur->address;
    free(trash);
  }
  return(first);
}
void main()
{
  int choice,item,pos;
  for(;;)
  {
    printf("1.Insert First\n2.Display\n3.Delete Position\n4.Delete First\n5.Delete Last\n6.Insert Position\n7.Insert Last\n8.Reverse\n9.Sort\n10.Remove Odd position elements\n11.Exit\nEnter choice:");
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
      case 6: printf("Enter value to be inserted\n");
      scanf("%d",&item);
      printf("Enter position\n");
      scanf("%d",&pos);
      first=insertpos(first,item,pos);
      break;
      case 7:printf("Enter value to be inserted\n");
      scanf("%d",&item);
      first=insertlast(first,item);
      break;
      case 8: first=reverse(first);
      break;
      case 9:first=sort(first);
      break;
      case 10: first=removeo(first);
      break;
      default: exit(0);
    }
  }
}
