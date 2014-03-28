/*
mse06h
spoj problem no. 4226
done :)

*/


#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;
int arr[1001];
int main(){
vector<int> vt[1001];
vector<int>::iterator it;

int test,n,m,val,index,l=1;
long int i,k;
long long int ans;
cin>>test;
while(l<=test){
	cin>>n>>m>>k;
	i=1;
	while(i<=k){
		scanf("%d",&index);
		scanf("%d",&val);
		vt[index].push_back(val);	
	i++;
	}
	
	memset(arr,0,sizeof(int)*(m+1));
	ans=0;
	
	for(i=n;i>=1;i--){
		if(vt[i].empty())
		continue;
		it=vt[i].begin();
		while(it!=vt[i].end()){
			index=*it;
			index--;
			while(index>0){
			ans+=arr[index];
			index -= index&-index;
			}
	 	//	cout<<"it="<<*it<<endl;
			it++;
		}
		it=vt[i].begin();
		while(it!=vt[i].end()){
			index=*it;
			while(index<=m){
				arr[index]++;
				index += index&-index;
			}
			it++;
			}
	//cout<<ans<<endl;
		vt[i].clear();
	}
	
	cout<<"Test case "<<l<<": "<<ans<<endl;
	l++;
}

return 0;
}
