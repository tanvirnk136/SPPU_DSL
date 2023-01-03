
#include<iostream>
#define max 5
using namespace std;
struct queue
{
int arr[max];
int front, rear;
}q;
class job
{
public:
job()
{
q.front=-1;
q.rear=-1;
} int isFull();
int isEmpty();
void Enqueue(int);
string Dequeue();
void display();
};
int job::isFull()
{
if(q.rear==max-1)
return 1;
else
return 0;
} int job::isEmpty()
{
if(q.front==q.rear)
return 1;
else
return 0;
}
void job::Enqueue(int m)
{
q.arr[++q.rear]=m;
}
string job::Dequeue()
{
if(!isEmpty())
{
q.front++;
return(to_string(q.arr[q.front]));
}
else
{
string t="No";
return (t);
}
}
void job::display()
{
if(!isEmpty())
{
cout<<"\nPending Jobs descending in priority:";
for(int i=q.front+1;i<=q.rear;i++)
cout<<"\n"<<q.arr[i];
}
else
cout<<"\nNo Jobs Pending.";
} int main()
{
job j;
string temp;
int ch,n;
while(true)
{
cout<<"\n---------------Menu----------------";
cout<<"\n\t1. Add a Job";
cout<<"\n\t2. Delete a Job";
cout<<"\n\t3. Display Pending Jobs";
cout<<"\n\t4. Exit";
cout<<"\nEnter Your Choice: ";
cin>>ch;
switch(ch)
{
case 1: if(!j.isFull())
{
cout<<"\nEnter the Job code: ";
cin>>n;
j.Enqueue(n);
}
else
{cout<<"\nQueue is Full!";}
break;
case 2: temp=j.Dequeue();
if(temp!="No")
cout<<"\nJob "<<temp<<" was deleted
successfully!";
else
cout<<"\nNo Job in Queue!";
break;
case 3: j.display();
break;
case 4: cout<<"\nEnd of program";
return (0);
default: cout<<"\nUnexpected Choice input! Try again...";
}
}
}