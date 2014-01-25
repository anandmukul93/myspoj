#include <iostream>
#include <algorithm>
#include <list>
#include <queue>
using namespace std;

int array[183][183];
bool arrcase[183][183];
int row, col;

struct node {
int i,j;
node(int x, int y){
  i=x;
  j=y;
}
node(){
i=0;j=0;
}
};


node arrmove[4];

node *temp;
queue<node *> bfslist; 

void takeInput(){
    cin>>row>>col;
    for(int i =1;i<=row;i++){
      for(int j =1 ;j<=col ; j++)
          {cin>>array[i][j];
          arrcase[i][j]=false;
          if(array[i][j]==1)
            {
            temp= (node *)malloc(sizeof(node));
            temp->i=i;
            temp->j=j;
            bfslist.push(temp);
            arrcase[i][j]=true;
            array[i][j]=0;
            }
          }
        }
      
}


void explore(int index){
  node * temp2;
  if(!arrcase[temp->i+arrmove[index].i][temp->j+arrmove[index].j])
    {array[temp->i+arrmove[index].i][temp->j+arrmove[index].j]=array[temp->i][temp->j]+1;
      arrcase[temp->i+arrmove[index].i][temp->j+arrmove[index].j]=true;
      temp2=(node *)malloc(sizeof(node));
      temp2->i=temp->i+arrmove[index].i;
      temp2->j=temp->j+arrmove[index].j;
      bfslist.push(temp2);
    }
}
void processInput(){
  int i , j;
    while(!bfslist.empty()){
        temp=bfslist.front();
        
        if(temp->i <row)
          explore(3);        
        if(temp->j <col)
          explore(1);
        if(temp->i >1)
          explore(2);
        if(temp->j>1)
        explore(0);
        
        bfslist.pop();
        delete temp;
        
    }
}

void printAnswer(){
for(int i=1;i<=row;i++){
  for(int j=1 ;j<=col;j++)
    cout<<array[i][j];
    cout<<endl;
    }
}


int main(){

    arrmove[0].i=0;arrmove[0].j=-1;
    arrmove[1].i=0;arrmove[1].j=1;
    arrmove[2].i=-1;arrmove[2].j=0;
    arrmove[3].i=1;arrmove[3].j=0;
    int cases;
    cin>>cases;
    while(cases--){
    takeInput();
    processInput();
    printAnswer();
    }
return 0;
}
