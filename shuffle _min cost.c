#include<stdio.h>
#include<conio.h>
#include<malloc.h>
int f=0;
struct node{
int data;
int cost;
struct node *next;
}*head=NULL,*temp,*add;
int suffle(int a[],int );

int min_cost();
void insert(int);
int isequal(int );
int costf(int );
void sarch_display(int);
void main()
{
	int k,n,h,i=0,*p,count=0,suffled;
	srand(time(NULL));
	printf("\t************************************\n\t*  display format:|numbers[cost]|  *\n\t*           by Pratap              *\n\t************************************");

	printf("\n Enter a number ::");
	scanf("%d",&n);
	h=n;
	while(n!=0)
	{
		n=n/10;
		count++;
	}
	p=(int *)malloc(sizeof(int)*count);
	i=-1;
	while(h!=0)
	{   i++;
		p[i]=h%10;
		h=h/10;
	}
do{
    k=suffle(p,count);
    insert(k);

    i++;
    if(f==fact(count))
        break;
}while(i<fact(count+2));
display();
printf("\n\n The minimum cost is %d \n",min_cost());
search_display(min_cost());
getch();
}
//for suffling
int suffle(int a[],int count)
{
	int temp,i,new_index,s=0;
	for(i=0;i<count;i++)
	{
		new_index=rand()%count;
		temp=a[i];

		a[i]=a[new_index];
		a[new_index]=temp;
	}

	for(i=0;i<count;i++)
	{
		s=s*10+a[i];

	}
return s;
}

void insert(int value)
{

        add=(struct node *)malloc(sizeof(struct node));
        add->data=value;

        if(head==NULL)
        {   add->cost=costf(value);
            add->next=NULL;
            head=add;
            temp=add;
            f++;

        }
        else
        {
            if(isequal(value))
            {
            return;
            }
            else
            {
            add->cost=costf(value);
            temp->next=add;
            add->next=NULL;
            temp=add;
            f++;
        }
 /*  }
    else
    {

        return;
    }*/

}
}
int isequal(int value)
{
    struct node *k;


    k=head;
    while(k!=NULL)
    {   if(k->data==value)
        return 1;
        k=k->next;

    }

        return 0;
}

void display()
{
int i=0;
    struct node *t;
    t=head;
    while(t!=NULL)
    {

        printf("\t%d   |%d [%d]| \n\n",i+1,t->data,t->cost);
        t=t->next;

   i++; }
}

int fact(int n)
{
int i,k=1;
    /*if(n==1)
        return 1;
    return n*fact(n-1);*/
for(i=n;i>=1;i--)
{
    k=k*i;

}
return k;
}

int costf(int n)
{	int i=0,j,r,c=0,*a,s=0,h=0;
	while(n!=0)
	{
		r=n%10;
		s=s*10+r;
		n=n/10;
		c++;
	}
	a=(int*)malloc(sizeof(int)*c);
	while(s!=0)
	{
		a[i]=s%10;
		i++;
		s=s/10;
	}

h=a[0]+a[1];
a[0]=h;
i=1;
    for(j=2;j<c;j++)
	{

	    h=h+a[j];
	    a[i]=h;
        i++;



    }
    s=0;
	for(i=0;i<c-1;i++)
     s=s+a[i];
return s;

}

int min_cost()
{
   struct node *s;
   int n;
   s=head;
   n=s->cost;
   while(s->next!=NULL)
   {
    if(n<=s->cost)
    {
        s=s->next;
    }
    else
    {
    n=s->cost;

    }
   }

   return n;
}
void search_display(int n)
{

    struct node *p;
    p=head;
    printf("\n MINIMUM COSTED INTEGER VALUES/VALUE ARE/IS::");
   do
    {
        if(n==p->cost)
            printf(" \n\n |%d [%d]|",p->data,p->cost);
    p=p->next;
    } while(p!=NULL);
}

