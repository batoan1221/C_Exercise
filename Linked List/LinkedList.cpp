#include <iostream>
#include <stdio.h>
#include <conio.h>

struct node {
	int Info;
	struct node* pNext;
};
typedef struct node NODE;

struct list{
	NODE* pHead;
	NODE* pTail;
};
typedef struct list LIST;

void init(LIST &l){
	l.pHead = NULL;
	l.pTail = NULL;
}

NODE* getNode(int x){
	NODE *p;
	p = new NODE;
	if(p==NULL){
		return NULL;
	}
	
	p->Info = x;
	p->pNext = NULL;
	
	return p;
}

NODE* getHead(LIST &l){
	if(l.pHead==NULL)
		return NULL;
	NODE *pResult = l.pHead;
	l.pHead = l.pHead->pNext;
	return pResult;
}

NODE* searchNode(LIST l,int x){
	for(NODE*p=l.pHead;p!=NULL;p=p->pNext){
		if(p->Info==x) return p;
	}
	return NULL;
}

void addHead(LIST &l,NODE* p){
	if(l.pHead==NULL){
		l.pHead = p;
		l.pTail = l.pHead;
	}
	else{
		p->pNext = l.pHead;
		l.pHead = p;
	}
}

void addTail(LIST &l,NODE *p){
	if(l.pHead==NULL)
		l.pHead=l.pTail=p;
	else{
		l.pTail->pNext=p;
		l.pTail=p;
	}
}

void addAfter(LIST &l,NODE *q,NODE *p){
	if(l.pHead==NULL && q==NULL){
		l.pHead=l.pTail=p;
	}
	if(q!=NULL){
		NODE* x = searchNode(l,q->Info);
		p->pNext = x->pNext;
		x->pNext = p;
	}
	if(q==l.pTail){
		l.pTail->pNext=p;
		l.pTail = p;
	}
}

void addBefore(LIST &l,NODE *q,NODE *p){
	NODE *x = l.pHead;
	NODE *t = l.pHead;
	while(t->Info!=q->Info&&t!=NULL){
		x=t;
		t=t->pNext;
	}
	if(x==l.pHead){
		addHead(l,p); 
		return;
	}
	addAfter(l,x,p);
}

void input(LIST &l){
	int n;
	printf("Enter number of node: ");
	scanf("%d",&n);
	
		
	init(l);
	if(n==0)
		return;
 	for(int i=1;i<=n;i++){
		int x;
		printf("Enter element %d: ",i);
		scanf("%d",&x);
		NODE *p = getNode(x);
		addHead(l,p);
	}
}

void processNode(NODE *node)
{
	if(node->pNext)
		processNode(node->pNext);
		
	printf("%4d", node->Info);
}

void xuat(LIST l){
	for(NODE*p=l.pHead;p!=NULL;p=p->pNext)
	{
		printf("%4d",p->Info);
	}
	printf("\n");
}

int isEmpty(LIST l){
	if(l.pTail)
		return 0;
	return 1;
}

int main()
{
	LIST list;
	NODE* p;
	NODE* q;
	int x,y;
	input(list);
	int n = 100;
	do{
		printf("1. Check the list is empty?\n2. Add an element to tail of the list.\n3. Add an element before an element of the list.\n4. Add an element after an element of the list.\n5. Get head element out of the list.\n6. Reverse the list.\n0. Exit from program.\nEnter your choice: ");
		scanf("%d",&n);
		
		switch(n){
			case 1: 
				if(isEmpty(list)){
					printf("The list is empty!\n");
					getch();
					break;
				}
				printf("The list is not empty!\n");
				xuat(list);
				getch();
				break;
			case 2:
				printf("Enter value of the new element: ");
				scanf("%d",&x);
				p = getNode(x);
				addTail(list,p);
				printf("The new list:\n");
				xuat(list);
				getch();
				break;
			case 3:
				printf("Enter value of the element you want to add before: ");
				scanf("%d",&x);
				while(!searchNode(list,x)){
					printf("The element you entered not available!\n");
					printf("Enter value of the element you want to add before again: ");
					scanf("%d",&x);
				}
				printf("Enter value of the new element: ");
				scanf("%d",&y);
				q = getNode(x);
				p = getNode(y);
				addBefore(list,q,p);
				printf("The new list:\n");
				xuat(list);
				getch();
				break;
			case 4:
				printf("Enter value of the element you want to add after: ");
				scanf("%d",&x);
				while(!searchNode(list,x)){
					printf("The element you entered not available!\n");
					printf("Enter value of the element you want to add after again: ");
					scanf("%d",&x);
				}
				printf("Enter value of the new element: ");
				scanf("%d",&y);
				q = getNode(x);
				p = getNode(y);
				addAfter(list,q,p);
				printf("The new list:\n");
				xuat(list);
				getch();
				break;
			case 5:
				printf("The head element: %4d\n",getHead(list)->Info);
				printf("The new list:\n");
				xuat(list);
				getch();
				break;
			case 6:
				xuat(list);
				printf("The new list:\n");
				processNode(list.pHead);
				getch();
				break;
			case 0:
				printf("Thank you for using our app :D!");
				getch();
				break;
			default:
				printf("Your choice is not available. Please choose again!\n");
				getch();
				break;
		}
	}
	while(n!=0);
	return 0;
}
