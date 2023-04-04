// FINDING LARGEST NODE IN DOUBLY LINKED LIST

#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	struct Node* prev;
	struct Node* next;
}dl;

dl* insert(dl*, dl*);
void largest(dl*, dl*);
main(){
	int ch;
	dl *head=NULL, *tail=NULL;
	do{
		printf("menu:-\n");
		printf("1. insertion....2. largest node....3.exit\n");
		printf("enter your choice:-\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:tail=insert(head,tail);  //inserting node at right hand side
			       if(head==NULL)
			           head=tail;
			       break;
			case 2:largest(head,tail);  //finding largest node in a linked list
			       break;
			case 3:exit(0);       
		}
	}while(ch<=3);
}

dl* insert(dl *head,dl *tail){
	int x;
	dl *p;
	p=(dl*)malloc(sizeof(dl));
	if(p!=NULL){
		printf("\n enter value you want to insert:-");
		scanf("%d",&x);
		p->data=x;
		if(tail==NULL){
			tail=p;
			p->next=NULL;
			p->prev=NULL;
		}
		else{
			tail->next=p;
			p->prev=tail;
			tail=p;
		}
	}
	return tail;
}

void largest(dl *head, dl *tail){
	int large=head->data;
	dl *tmp=head;
	while(tmp!=NULL){
		if(tmp->data > large){
			large=tmp->data;
		}
		tmp=tmp->next;
	}
	printf("largest node in linked list is:-%d\n",large);
}
