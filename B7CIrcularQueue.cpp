
#include<iostream>
#define size 5
using namespace std;
int front=-1;
int rear=-1;
string cq[size];
void Enqueue(string m)
{
if(front==-1)
{ front=0;
rear=(rear+1)%size;
cq[rear]=m;
cout<<"\nOrder taken succesfully!";
}
else
{ rear=(rear+1)%size;
cq[rear]=m;
cout<<"\nOrder taken succesfully!";
}
}
string Dequeue()
{
if(front==-1)
{
cout<<"\nNo orders in queue";
return("Fail");
}
else
{
string temp=cq[front];
if(front==rear)
front=rear=-1;
else
front=(front+1)%size;
return temp;
}
}
void display()
{
if(front==-1)
{
cout<<"\nNo orders in queue";
}
else
{
cout<<"\nPending Orders:";
int i=front;
while(i!=rear)
{
cout<<"\n\t"<<cq[i];
i=(i+1)%size;
}
cout<<"\n\t"<<cq[i];
}
}
int main()
{
int ch;
string t;
while(true)
{
cout<<"\n\n---------------Menu-----------------";
cout<<"\n\t1. Order a Pizza";
cout<<"\n\t2. Display Pending orders";
cout<<"\n\t3. Pay & Deliver Pizza";
cout<<"\n\t4. Exit";
cout<<"\nEnter your choice: ";
cin>>ch;
switch(ch)
{
case 1: if(((rear==size-1)&&(front==0)) || (front==(rear+1)%size))
cout<<"\nSorry!\nMaximum orders reached";
else
{
cout<<"\nPizza menu";
cout<<"\n\tA. Paneer Pizza";
cout<<"\n\tB. Cheese Pizza";
cout<<"\n\tC. Pineapple Pizza";
cout<<"\n\tD. Peri Peri Pizza";
cout<<"\n\tE. Farm Pizza";
cout<<"\nEnter the index char of pizza to order:
";
cin>>t;
Enqueue(t);
}
break;
case 2: display();
break;
case 3: t=Dequeue();
if(t!="Fail")
cout<<"Pizza "<<t<<" was delivered!";
break;
case 4: return 0;
default: cout<<"\nWrong Choice, Try again....";
break;
}}
}