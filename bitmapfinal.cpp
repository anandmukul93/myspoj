#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int arrstatus[183][183];
int arr[183][183];
int row, col;
queue<int>iindex;
queue<int>jindex;

void printAnswer();
void takeInput(){
char ch;
scanf("%c",&ch);
	for(int i =1; i<=row;i++){
		for(int j=1;j<=col;j++)
			{
			scanf("%c",&ch);
			if(ch=='1')
			{
			arrstatus[i][j]=1;
			arr[i][j]=0;
			iindex.push(i);
			jindex.push(j);
			}
			}
			scanf("%c",&ch);
	}
}

void initialize(){
	for(int i =1; i<=row;i++)
	{
		for(int j=1;j<=col;j++)
		arrstatus[i][j]=0;
	}
}

void bfvisit(int i  , int j ,int value){
	if(arrstatus[i][j]==0)
		{
		arrstatus[i][j]=1;
		arr[i][j]=value+1;
		iindex.push(i);
		jindex.push(j);
		}
}

void process(){
	int i,j,value;
	while(!iindex.empty())
	{
		i=iindex.front();
		j=jindex.front();
		value=arr[i][j];
		if(i<row)
		bfvisit(i+1,j,value);
		if(j<col)
		bfvisit(i,j+1,value);
		if(i>1)
		bfvisit(i-1,j,value);
		if(j>1)
		bfvisit(i,j-1,value);
		
		iindex.pop();
		jindex.pop();
	}
}


void printAnswer(){
for(int i =1; i<=row;i++)
	{
		for(int j=1;j<=col;j++)
		cout<<arr[i][j]<<' ';
		cout<<endl;
	}
}

int main(){
int cases;
cin>>cases;
while(cases--){
cin>>row>>col;
initialize();
takeInput();
process();
printAnswer();
}
return 0;
}
