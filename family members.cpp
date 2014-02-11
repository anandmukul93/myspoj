#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;
 int main(){
	long int t,W;
	long int x,y,parent,midi,midj; 
	int i,j,level ;
	double ans;
	cin>>t ;
	while(t--){
	i=j=0;
		cin>>x>>y>>W;
		i=floor(log2(x));
		j=floor(log2(y));
		parent=1,level=0;
		while(parent<min(x,y))	{
			midi=(parent*2+1)*pow(2,i-level-1);
			midj=(parent*2+1)*pow(2,j-level-1);
			if(x>=midi && y<midj || x<midi && y>=midj)
			break;
			else if(x>=midi && y>=midj)
			parent=parent*2+1;
			else 
			parent*=2;
			level++;
		}
		i=1;j=1;
		while(y!=parent)
		{
			if(y&1 && (y/2)&1)
			j*=4;
			else
			j*=2;
			y/=2;
		}
		while(x!=parent)
		{
		if(x&1 && (x/2)&1)
			i*=4;
			else
			i*=2;
			x/=2;
		}
	ans=(double)(W*i)/j;
	printf("%.6lf\n",ans);
}
return 0;
}
