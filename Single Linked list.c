#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}node;

node *first=NULL;
node *tail=NULL;

void create()
{
	int ele;
	printf("\nEnter the element you want to enter\n");
	scanf("%d",&ele);
	node* newnode;
	newnode=(node*)malloc(sizeof(node));
	newnode->data=ele;
	newnode->next=NULL;
	if(first==NULL)
	{
		first=newnode;
		tail=newnode;
		return;
	}
	else
	{
	tail->next=newnode;	
	tail=newnode;
}
}
void display()
{
	node* temp=first;
	if(first==NULL)
	{
		printf("\nThe list is empty\n");
		return;
	}
	else{ while(temp!=NULL){
	
		printf("%d ",temp->data);
		temp=temp->next;
	}
	}	
}

void insertbegin()
{
    int ele;
	printf("\nEnter the element you want to enter\n");
	scanf("%d",&ele);
	node* newnode;
	newnode=(node*)malloc(sizeof(node));
	newnode->data=ele;
	newnode->next=NULL;
	if(first==NULL)
	{
		first=newnode;
		tail=newnode;
		return;
	}
	else
	{
		newnode->next=first;
		first=newnode;
		printf("\n %d is inserted at first\n",newnode->data);
	}	
}
void insertlast()
{
	int ele;
	printf("\nEnter the element you want to enter\n");
	scanf("%d",&ele);
	node* newnode;
	newnode=(node*)malloc(sizeof(node));
	newnode->data=ele;
	newnode->next=NULL;
	if(first==NULL)
	{
		first=newnode;
		tail=newnode;
		return;
	}
	else
	{
		tail->next=newnode;
		tail=newnode;
		printf("\n %d is inserted at end\n",newnode->data);
	}
	
}
void insertbypos()
{
	int ele;
	printf("\nEnter the element you want to enter\n");
	scanf("%d",&ele);
	int pos;
	printf("\nEnter the position where you want to enter\n");
	scanf("%d",&pos);
	node* newnode;
	node* temp=first, *prev;
	newnode=(node*)malloc(sizeof(node));
	newnode->data=ele;
	newnode->next=NULL;
	if(pos==0)
    {
    newnode->next = first;
    first = newnode;
    printf("%d is inserted at position 0\n", newnode->data);
    return;
	}
	int i;
	for(i=0;temp!=NULL && i<pos;i++)
	{
		prev=temp;
		temp=temp->next;
	}
	if(i!=pos)
	{
		printf("\nThe given position is beyond the length of the list\n");
		free(newnode);
		return;
	}
	prev->next=newnode;
	newnode->next=temp;
	printf("\n%d is inserted at position %d\n",newnode->data,pos);
}
void deletefirst()
{
	node* temp=first;
	if(first==NULL)
	{
		printf("\nThe list is empty\n");
		return;
	}
	printf("\n %d is deleted\n",temp->data);
	first=first->next;
	free(temp);
}
void deletelast()
{
	node* temp=first, *prev;
	if(first==NULL)
	{
		printf("\nThe list is empty\n");
		return;
	}
	while(temp->next!=NULL)
	{
		prev=temp;
		temp=temp->next;
	}
	prev->next=NULL;
	tail=prev;
	printf("\n %d is deleted\n",temp->data);
	free(temp);
}
void deletebypos()
{   int pos;
    printf("\nEnter the position where you want to delete the element\n");
    scanf("%d",&pos);
	node *temp = first, *prev = NULL;
	if(first==NULL)
	{
		printf("\nThe list is empty\n");
		return;
	}
	if(pos==0)
	{
	temp=temp->next;
	printf("\n %d is deleted\n",temp->data);
	free(temp);	
	}
	int i;
	for(i=0;temp!=NULL && i<pos;i++)
	{
		prev=temp;
		temp=temp->next;
	}
	if(i!=pos)
	{
		printf("\nThe given position is beyond the length of the list\n");
		return;
	}
	prev->next=temp->next;
	printf("%d deleted\n", temp->data);
    free(temp);
	}

void max()
{
	int max=0;
	if(first==NULL)
	{
		printf("\nThe list is empty\n");
		return;
	}
	node *temp=first;
	while(temp!=NULL)
	{
		if(temp->data>max)
		{
			max=temp->data;
		}
		temp=temp->next;
	}
	printf("Maximum element in the Linked List is :%d\n",max);
}	
	
void min()
{
	if(first==NULL)
	{
		printf("\nThe list is empty\n");
		return;
	}
	node *temp=first;
	int min=temp->data;
	while(temp!=NULL)
	{
		if(temp->data<min)
		{
			min=temp->data;
		}
		temp=temp->next;
	}
	printf("Minimum element in the Linked List is :%d\n",min);	
}

void count()
{
	int c=0;
	if(first==NULL)
	{
		printf("\nThe list is empty\n");
		return;
	}
	node *temp=first;
	while(temp!=NULL)
	{
    c++;
    temp=temp->next;
    }
  printf("No.of Nodes in the Linked List is %d\n",c);
}

void sumandproduct()
{
	if(first==NULL)
	{
		printf("\nThe list is empty\n");
		return;
	}
	int sum=0,prod=1;
	node *temp=first;
	while(temp!=NULL){
    sum=sum+temp->data;
    prod=prod*temp->data;
    temp=temp->next;
  }
  printf("\nsum of all the elements =%d\n",sum);
  printf("\nproduct of all the elements =%d\n",prod);
}	
	
	
void search()
{
	int ele;
	printf("\nEnter the element you want to search\n");
	scanf("%d",&ele);
	node *temp=first;
	int x=0;
	while(temp!=NULL)
	{
		if(temp->data==ele)
		{
		 printf("%d is found at %d poistion\n",ele,x);
		 x++;
		}
		
		temp=temp->next;
	}
	if(x==0)
	{
	printf("%d is not found in the list\n",ele);	
	}	
}

void sorting()
{
	if(first==NULL)
	{
		printf("\nThe list is empty\n");
		return;
	}
	node *temp1=first, *temp2;
    while(temp1!=NULL)
    {
    	temp1=temp1->next;
    	while(temp2!=NULL)
    	{
    		if(temp1->data>temp2->data)
    		{
    			int t=temp1->data;
    			temp1->data=temp2->data;
    			temp2->data=t;
			}
			temp2=temp2->next;
		}
		temp1=temp1->next;
	}
}
void reverse()
{
	if(first==NULL)
	{
		printf("\nThe list is empty\n");
		return;
	}
	node* prev=NULL;
	node *curr=first;
	node *nextnode=NULL;
	while(curr!=NULL)
	{
		nextnode=curr->next;
		curr->next=prev;
		prev=curr;
		curr=nextnode;
	}
	first=prev;
}
int main()
{
	int choice;
	printf("\n1.create a node\n2.display\n3.insert at the begin\n4.insert at the end\n5.insert by position\n6.delete at begin\n7.delete at end\n8.delete by position\n9. maximum element\n10.minimum element\n11.count\n12.sum and product\n13.Search\n14.Sorting\n15.Reverse\n");
	while(1)
	{
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: create();
			break;
			case 2: display();
			break;
			case 3: insertbegin();
			break;
			case 4: insertlast();
			break;
			case 5: insertbypos();
			break;
			case 6: deletefirst();
			break;
			case 7: deletelast();
			break;
			case 8: deletebypos();
			break;
			case 9: max();
			break;
			case 10: min();
			break;
			case 11: count();
			break;
			case 12: sumandproduct();
			break;
			case 13: search();
			break;
			case 14: sorting();
			break;
			case 15: reverse();
			break;
			default: printf("\n INVALID CASE\n");
		}
	}
}