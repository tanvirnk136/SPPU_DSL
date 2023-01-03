#include<iostream>
#include<stdlib.h>
#define SIZE 80
using namespace std;
class mystack
{
private :
char ST[SIZE];
int top;
public :
mystack();
void push(char X);
char pop();
int isEmpty();
int isFull();
};
mystack :: mystack()
{
top = -1;
}
int mystack :: isEmpty()
{
if(top == -1)
return 1;
else
return 0;
}
int mystack :: isFull()
{
if(top == SIZE-1)
return 1;
else
return 0;
}
void mystack :: push(char X)
{
if(!isFull())
{
top++;
ST[top] = X;
}
else
cout<<"\nStack Overflow !! Error!!";
}
char mystack :: pop()
{
if(!isEmpty())
{
char X = '\0';
X = ST[top];
top--;
return X;
}
else
cout<<"\nStack underflow!";
}
/*void convert_string(char Str[],char Str1[])
{
int i,j = 0;
for(i=0;Str[i] != '\0';i++)
{
if(Str[i] >= 'a' && Str[i] <= 'z')//ascii a - z 97 -122
Str1[j++] = Str[i];
if(Str[i] >= 'A' && Str[i] <= 'Z')//ascii A - Z 65 -90
Str1[j++] = Str[i] + 32;
if(Str[i] >= '0' && Str[i] <= '9')
Str1[j++] = Str[i];
}
Str1[j] = '\0';
}*/
int main()
{
int ch,flag,i;
char Str[80];
char temp='\0';
mystack S;
system("clear");
do
{
cout<<"\n\t\t\t1 : Check for correct parenthesis";
cout<<"\n\t\t\t2 : Exit";
cout<<"\n\nEnter ur choice : ";
cin>>ch;
switch(ch)
{
case 1 : cout<<"\nEnter the string to be checked: ";
cin.ignore();
cin.getline(Str,80);
cout<<"\nEntered String is "<<Str;
flag=1;
for(i=0;Str[i]!='\0';i++)
{
if((Str[i]=='{') || (Str[i]=='[') || (Str[i]=='('))
S.push(Str[i]);
if((Str[i]=='}') || (Str[i]==']') || (Str[i]==')'))
{
temp=S.pop();
if((Str[i]=='}' && temp=='{') || (Str[i]==']'
&& temp=='[') || (Str[i]==')' && temp=='('))
continue;
else
{
flag=0;
break;
}
}
} if(flag==1)
cout<<"\nString is well parenthesised";
else
cout<<"\nString is not parenthesised well!";
break;
case 2 : cout<<"\nEnd of Program\n";
return 0;
default: cout<<"\nInvalid choice !! Try again\n\n";
}
}while(true);
}