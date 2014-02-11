// longest common subsequence of two strings with max length 1000



#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
int matrix[10001];
int main() {
	char st1[10001],st2[10001];
	int len1,len2,numtest;
	int top, diag;
	cin>>numtest;
	while(numtest--){
		scanf("%s",st1);
		scanf("%s",st2);
		len1=strlen(st1);
		len2=strlen(st2);
		memset(matrix,0,10001);
		for(int i =1;i<=len1;i++){
			matrix[0]=0;
			diag=0;
			for(int j =1;j<=len2;j++){
				top=matrix[j];
				if(st1[i-1]==st2[j-1])
					matrix[j]=diag+1;
				else
					matrix[j]=max(matrix[j-1],top);
				diag=top;
				
			}	
			
		}
		cout<<matrix[len2]<<endl;
	}
	// your code goes here
	return 0;
}
