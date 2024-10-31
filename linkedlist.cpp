//code for single linked list
#include <stdio.h>
#include <stdlib.h>
void creation();
void display();
void insertion();
void deletion();
void search();
int length();
struct node
{
	int data;
	struct node *next;
};
struct node *temp,*newnode,*head,*nextnode;
int  main()
{
     head=0;
     int choicee=1;
 while(choicee==1)
 {
 newnode=(struct node *)malloc(sizeof(struct node));
 printf("Enter Data:");
 scanf("%d",&newnode->data);
 newnode->next=0;
 if(head==0)
 {
 head=temp=newnode;
 }
 else
 {
 	temp->next=newnode;
 	temp=newnode;
 }
  printf("Enter 0 to stop or 1 to continue:");
  scanf("%d",&choicee);
 }
 int choice=0;
 for(choice;choice!=5;choice=choice+0)
 {
 printf("select opertion:1.display 2.insertion 3.deletion 4.search 5.exit:");
	scanf("%d",&choice);
		switch(choice)
		{
		
			case 1:display();
			break;
			case 2:insertion();
			break;
			case 3:deletion();
			break;
			case 4:search();
			break;
			case 5:exit(0);
			break;
			default:printf("Invalid Choice");
			choice=choice+0;
		}
 }
 return 0;
	}


void display()
{
    printf("elements are:\n");
	temp=head;
	while(temp!=0)
	{
		printf("%d\n",temp->data);
		temp=temp->next;
	}
}
void insertion()
{
	int pos,x,i=1;
	x=length();
	temp=head;
	printf("Enter position:");
	scanf("%d",&pos);
	if(pos>x)
	printf("Invalid Positon\n");
	else
	{
	  while(i<pos-1)
	  {
	  	temp=temp->next;
	  	i++;
	  }	
	   newnode=(struct node *)malloc(sizeof(struct node));
	  printf("Enter new Data:");
	  scanf("%d",&newnode->data);
	  newnode->next=temp->next;
	  temp->next=newnode;
	}
}
void deletion()
{
	
	int pos,i=1,y;
	y=length();
	temp=head;
	printf("Enter Position ");
	scanf("%d",&pos);
	if(pos>y)
	printf("Invalid Position");
	else
	{
		while(i<pos-1)
		{
			temp=temp->next;
			i++;
		}
		nextnode=temp->next;
		temp->next=nextnode->next;
		free(nextnode);
		
	}
	
}
void search()
{
	int key,flag=0;
	temp=head;
	printf("Enter key: ");
	scanf("%d",&key);
	while(temp!=NULL)
	{
		if(temp->data==key)
		{
			flag=1;
		}
		temp=temp->next;
	}
	if(flag==1)
	printf("Key is found");
	else
	printf("Key is not found");
}
int length()
{
	int count=0;
	temp=head;
	while(temp!=0)
	{
	    count++;
		temp=temp->next;
	}
	return count;
}