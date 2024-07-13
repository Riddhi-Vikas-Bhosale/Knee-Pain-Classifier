//============================================================================
// Name        : dll_6.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include<iostream>
using namespace std;

class dnode
{
	int data;
	dnode *prev;
	dnode *next;
public:
	dnode(int d)
{
		data=d;
		prev=NULL;
		next=NULL;
}
	friend class dlist;
};

class dlist
{
	dnode *start;
public:
	dlist()
{
		start=NULL;
}
	void create();
	void display();
	void merge(dlist,dlist);
};

void dlist::create()
{
	int d;
		dnode *temp,*ptr;
		char choice;
		do
		{
		cout<<"Enter numbers in non-decreasing order:";
		cin>>d;
		temp=new dnode(d);
		if(start==NULL)
		{
			start=temp;
		}
		else
		{
			ptr=start;
		while(ptr->next!=NULL)
		{
		 ptr=ptr->next;
		}
		ptr->next=temp;
		temp->prev=ptr;
		}
		cout<<"do you want to continue?";
		cin>>choice;
		}while(choice=='y'||choice=='Y'||choice=='1');
}

void dlist::display()
{

	dnode *ptr;//*start,*temp;
	//int d;
		ptr=start;
		while(ptr->next!=NULL)
		{
			cout<<"\t"<<ptr->data;

			//cout<<endl;
			ptr=ptr->next;
		}
		cout<<"\t"<<ptr->data;
		cout<<"\n";
}
void dlist::merge(dlist l1,dlist l2)
{
	dnode *p1,*p2,*ptr;
	dlist l3;
p1=l1.start;
p2=l2.start;
ptr=l3.start;
while(p1!=NULL && p2!=NULL)
{
	if(p1->data < p2->data)
	{
	  if(ptr==NULL)
	  {
		l3.start=p1;
		ptr=p1;
		 //p1=ptr->next;
	  }else
	  {
		  ptr->next=p1;
		  p1->prev=ptr;
		  ptr=ptr->next;

	  }p1=p1->next;

	}

	  if(p1->data > p2->data)
	  {

		  if(ptr==NULL)
		  {
			l3.start=p2;
			ptr=p2;
			// ptr=ptr->next;
		  }else
		  {
			  ptr->next=p2;
			  p2->prev=ptr;
			  ptr=ptr->next;

		  }p2=p2->next;
         }

   if(p1!=NULL)
    {
	 ptr->next=p1;
    }
   if(p2!=NULL)
   {
	   ptr->next=p2;
   }
}
cout<<"\nMerged list is:\n";
l3.display();

}
int main()
{
dlist d1,d2,d3;
int choice,ch;
//char ch;

do
{
cout<<"\nEnter your choice:\n1.Create 1st list\n2.Create 2nd list\n3.Merge both lists";
cin>>choice;
switch(choice)
{
case 1:
	d1.create();
    d1.display();
break;
case 2:
	d2.create();
	d2.display();
	break;
case 3:
    d3.merge(d1,d2);
    //l3.display();
    break;
}
cout<<"\nDo you want to continue?\n1.yes\n2.no";
cin>>ch;
}while(ch==1);

}



/*

===============================OUTPUT===============================


Enter your choice:
1.Create 1st list
2.Create 2nd list
3.Merge both lists1
Enter numbers in non-decreasing order:2
do you want to continue?1
Enter numbers in non-decreasing order:4
do you want to continue?1
Enter numbers in non-decreasing order:6
do you want to continue?2
	2	4	6

Do you want to continue?
1.yes
2.no1

Enter your choice:
1.Create 1st list
2.Create 2nd list
3.Merge both lists2
Enter numbers in non-decreasing order:1
do you want to continue?1
Enter numbers in non-decreasing order:3
do you want to continue?1
Enter numbers in non-decreasing order:5
do you want to continue?2
	1	3	5

Do you want to continue?
1.yes
2.no1

Enter your choice:
1.Create 1st list
2.Create 2nd list
3.Merge both lists3

Merged list is:
	1	2	3	4	5	6

Do you want to continue?
1.yes
2.no2






*/
