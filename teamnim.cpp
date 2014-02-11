#include <iostream>
#include <string>
#include <cstdio>
using namespace std; 

int main(){
string team1="Aviendha/Birgitte";
string team2= "Elayne/Nynaeve";
long int x ,y , z;
int t;
String player1,player2,player3,player4;
cin>>t;
while(t--)
{
	cin>>x>>y>>z;
	cin>>player1>>player2>>player3>>player4;
	if(team1.find(player1)!=string::npos && team1.find(player2)!=string::npos)
		dec1=1;
	else 
		dec1=0;
	if(x^y^z)
		dec2=1;
	else 
		dec2=0;
	if(dec1|dec2)
	{
		if(!(player1.compare("Elayne")&&player1.compare("Nyanaeve")))
		cout<<team2<<endl;
		else
		cout<<team1<<endl;

	}
	else
	{
	if(player1.equals("Elayne")|| player1.equals("Nyanaeve"))
		cout<<team1<<endl;
		else
		cout<<team2<<endl;
	

	}
}

return 0;
}
