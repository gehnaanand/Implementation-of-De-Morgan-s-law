#include <stdio.h>
#include <stdlib.h>
#define RED   "\x1B[41;1m" //background & bold
#define BLU   "\x1B[34;1m" //bold
#define GRN   "\x1B[42m"   //background
#define red   "\x1B[31;1m" //text & bold
#define CYN   "\x1B[36;1m"
#define MAG   "\x1B[35;1m"
#define mag   "\x1B[45;1m" //background & bold
#define YEL   "\x1B[33m"
#define BLINK  "\x1B[25m"
#define BOLD  "\x1B[1m"
#define UNDER "\x1B[4m"
#define RESET "\x1B[0m"

struct node
{
	int info;
	struct node*next;

};

struct node*getnode();
struct node*create();
struct node*create1(struct node*);
struct node*insert_rear(int,struct node*);
int search(int,struct node*);
void display(struct node*);
struct node*Union(struct node*,struct node*);
struct node*intersection(struct node*,struct node*);
struct node*complement(struct node*,struct node*);
struct node*sort(struct node*);
struct node*remove_duplicate(struct node*);

void main()
{
	int n;
	struct node*U,*I,*lhs,*x,*y,*rhs,*lhs1,*rhs1,*u=NULL;
	struct node*a=NULL;
	struct node*b=NULL;

	for(;; )
	{
		printf("\t--------------------------------------------------\n");
		printf("\n\tEnter \n\t1.To create and display the universal set\n\t2.To create two subsets and display\n \t3.Union of both subsets \n\t4.Intersection of both subsets \n\t5.De-Morgan's 1st law \n\t6.De-Morgan's 2nd law \n\t7.To exit\n\n");
		printf("\t--------------------------------------------------\n");
		printf("\t\tEnter your choice: ");
		scanf("%d",&n);
		printf("\n");
		switch(n)
		{
			case 1: printf("\t");
				printf(YEL "Enter universal set :"RESET "\n");
				u=create();
				u=remove_duplicate(u);
				u=sort(u);
				printf("\n");
				display(u);
				printf("\n");
				break;

			case 2: if(u==NULL)
				{
					printf("\t");
					printf(red "INVALID......Create a universal set"RESET "\n");
				}
				else
				{
					printf("\t");
					printf(YEL "\n\tEnter set A:"RESET "\n");
					a=create1(u);
					a=remove_duplicate(a);
					printf(CYN "\tSET A = "RESET);
					a=sort(a);
					display(a);
					printf("\n");
					printf("\t");
					printf(YEL "\n\tEnter set B:"RESET "\n");
					b=create1(u);
					b=remove_duplicate(b);
					printf("\t");
					printf(CYN "SET B = "RESET);
					b=sort(b);
					display(b);
					printf("\n"); 
				}
				break;

			case 3: if(u==NULL||(a==NULL && b==NULL))
				{
					printf("\t");
					printf(red "INVALID-------Create 2 subsets"RESET "\n");
				}
				else
				{
					printf("\t");
					printf(CYN "(A U B) = "RESET);
					U=Union(a,b);
					U=sort(U);
					display(U);
					printf("\n");
				}
				break;

			case 4: if(u==NULL||(a==NULL && b==NULL))
				{
					printf("\t");
					printf(red "INVALID-------Create 2 subsets"RESET "\n");
				}
				else
				{
					printf("\t");
					printf(CYN "(A ^ B) = "RESET);
					I=intersection(a,b);
					I=sort(I);
					display(I);
					printf("\n");
				}
				break;

			case 5:
				printf("\t");
				printf(MAG "De Morgan's 1st law"RESET "--->");
				printf(CYN "(A U B)'= A' ^ B'"RESET "\n\n");

				if(u==NULL||(a==NULL && b==NULL))
				{
					printf("\t");
					printf(red "INVALID-------Create 2 subsets"RESET "\n");
				}
				else
				{
					printf("\t\t");
					printf(BLINK UNDER mag "------De Morgan's 1st law-----" RESET "\n\n\n");
					printf("\t");
					printf(YEL " ------------------LHS--------------------"RESET "\n\n");
					printf("\t");
					printf(MAG " (A U B) = "RESET);
					U=Union(a,b);
					U=sort(U);
					display(U);
					printf("\n");
					printf("\t");
					printf(CYN " (A U B)' = "RESET);

					lhs=complement(U,u);
					lhs=sort(lhs);
					display(lhs);
					printf("\n");
					printf("\t");
					printf(YEL "------------------RHS--------------------"RESET "\n\n");
					printf("\t");
					printf(MAG " A'= "RESET);
					x=complement(a,u);
					x=sort(x);
					display(x);
					printf("\n");
					printf("\t");
					printf(MAG " B'= "RESET);
					y=complement(b,u);
					y=sort(y);
					display(y);
					printf("\n");
					printf("\t");
					printf(CYN " (A' ^ B') = "RESET);
					rhs=intersection(x,y);
					rhs=sort(rhs);
					display(rhs);
					printf("\t-------------------------------------------------------");
					printf("\t");
					printf("\n \n"MAG "\tLHS = "RESET);
					display(lhs);
					printf("\n"MAG "\tRHS = "RESET);
					display(rhs);
					printf("\n");

					printf("\t");

					printf(MAG "LHS = RHS"RESET "\n\n"CYN "\tTherefore (A U B)'= A' ^ B'"RESET "\n");
				}
				break;

			case 6:
				printf("\t");
				printf(MAG " De Morgan's 2nd law"RESET "--->");
				printf(CYN " (A ^ B)'= A' U B'"RESET "\n\n");
				if(u==NULL||(a==NULL && b==NULL))
				{
					printf("\t");
					printf(red " INVALID-------Create 2 subsets"RESET "\n");
				}
				else
				{
					printf("\t\t");
					printf(UNDER mag "-------De Morgan's 2nd law------"RESET "\n\n\n");
					printf(YEL "\t------------------LHS--------------------"RESET "\n");
					printf(MAG "\t(A ^ B)="RESET);
					I=intersection(a,b);
					I=sort(I);
					display(I);
					printf("\n");
					printf(CYN "\t(A ^ B)'="RESET);
					lhs1=complement(I,u);
					lhs1=sort(lhs1);
					display(lhs1);
					printf("\n");
					printf(YEL "\t------------------RHS--------------------"RESET "\n");
					printf("\t");
					printf(MAG "A' = "RESET);
					x=complement(a,u);
					x=sort(x);
					display(x);
					printf("\n");
					printf("\t");
					printf(MAG "B' = "RESET);
					y=complement(b,u);
					y=sort(y);
					display(y);
					printf("\n");
					printf("\t");
					printf(CYN "(A'U B') = "RESET);
					rhs1=Union(x,y);
					rhs1=sort(rhs1);
					display(rhs1);
					printf("\t-------------------------------------------------------");
					printf("\t");
					printf("\n \n"MAG "\tLHS = "RESET);
					display(lhs1); printf("\n"MAG "\tRHS = "RESET);
					display(rhs1);
					printf("\n");
					printf("\t");
					printf(MAG "LHS = RHS"RESET "\n"CYN "\tTherefore (A ^ B)'= A' U B'"RESET "\n");
				}
				break;

			default: exit(0);
				 break;
		}
	}
}

struct node*create()
{
	struct node*p,*last,*start=NULL;
	int item;
	printf("\t");
	printf(YEL "Enter the data and -1 to stop"RESET "\n");
	printf("\t");
	scanf("%d",&item);

	if(item==-1)
	return NULL;
	else
	{
		while(item!=-1)
		{
			p=getnode();
			p->info=item;
			p->next=NULL;
			if(start==NULL)
			{
				start=p;
				last=p;
			}
			else
			{
				last->next=p;
				last=p;
			}
			printf("\t");
			scanf("%d",&item);
		}
		return start;
	}
}

struct node*create1(struct node*u)
{
	struct node*start=NULL;
	struct node*p,*last;

	int item,flag=0;
	printf("\t");
	printf(YEL "Enter the data and -1 to stop "RESET "\n");
	printf("\t");
	scanf("%d",&item);

	while(item!=-1)
	{
		flag=search(item,u);
		if (flag==1)
		{
			p=getnode();
			p->info=item;
			p->next=NULL;
			if(start==NULL)
			{
				start=p;
				last=p;
			}
			else
			{
				last->next=p;
				last=p;
			}
		}
		else
		printf(CYN "\tElement not found in universal set, enter another number"RESET "\n");
		printf("\t");
		scanf("%d",&item);
	}
	return start;

}
struct node*insert_rear(int item,struct node*top)
{
	struct node*p,*last;
	p=getnode();
	p->info=item;
	p->next=NULL;

	if(top==NULL)
	{
		return p;
	}
	else
	{
		last=top;
		while(last->next!=NULL)
		{
			last=last->next;
		}
		last->next=p;
	}
	return top;
}

int search(int item,struct node*top)
{
	struct node*p;

	if(top==NULL)
	return 0;

	p=top;
	while(p!=NULL)
	{
		if(p->info==item)
		{
			return 1;
		}
		p=p->next;
	}
	return 0;

}

void display(struct node* start)
{
	struct node*p;

	if(start==NULL)
	{
		printf("\n\t");
		printf(red "Set is empty "RESET "\n\n");
	}
	else
	{
		printf("\t");
		p=start;
		while(p!=NULL)
		{

			printf(RED " %d " RESET,p->info);
			printf(GRN "  " RESET BLU "-->" RESET);
			p=p->next;

		}

		printf(red "NULL"RESET "\n\n");
	}
}
struct node*getnode()
{
	struct node*x;
	x=(struct node*)malloc(sizeof(struct node));
	if(x==NULL)
	{
		printf("\n\tOut of memory :\n");
		exit(0);
	}
	return x;
}
struct node*Union(struct node*first,struct node*second)
{
	struct node*c=NULL;
	struct node*a;
	int flag;

	if(first==NULL)
	return second;
	if(second==NULL)
	return first;

	a=first;
	while(a!=NULL)
	{
		c=insert_rear(a->info,c);
		a=a->next;
	}

	a=second;
	while(a!=NULL)
	{
		flag=search(a->info,c);

		if(flag==0)
		c=insert_rear(a->info,c);

		a=a->next;
	}
	return c;
}
struct node*intersection(struct node*first,struct node*second)
{
	struct node*c=NULL;
	struct node*a,*b;
	int flag=0;

	if(first==NULL||second==NULL)
	return NULL;

	a=first;
	b=second;
	while(a!=NULL)
	{
		flag=search(a->info,b);
		if(flag==1)
		c=insert_rear(a->info,c);

		a=a->next;
	}
	return c;
}
struct node*complement(struct node*start,struct node*u)
{
	struct node*p,*c=NULL;
	int flag=0;

	if(u==NULL)
	{
		printf(red "INVALID--------Create a universal list\n");
		return NULL;
	}

	if(start==NULL)
	return u;

	else
	{
		p=u;
		while(p!=NULL)
		{
			flag=search(p->info,start);

			if(flag==0)
			c=insert_rear(p->info,c);

			p=p->next;
		}
		return c;
	}
}
struct node* sort(struct node*first)
{
	struct node*p,*q;

	if(first==NULL)
	return NULL;
	else
	{
		for(p = first; p->next!= NULL; p = p->next)
		{
			for(q=p->next; q!= NULL; q=q->next)
			{
				if(p->info > q->info)
				{
					int temp = p->info;
					p->info = q->info;
					q->info = temp;
				}
			}
		}
		return first;
	}
}
struct node*remove_duplicate(struct node*first)
{
	struct node*a,*b;
	int flag=0;
	if(first==NULL)
		return NULL;
	
	b=NULL;
	a=first;
	
	while(a!=NULL)
	{
		flag=search(a->info,b);
		
		if(flag==0)
		{
			b=insert_rear(a->info,b);
			a=a->next;
		}
		else
			a=a->next;
	}
	return b;
}				
				
