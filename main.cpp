#define REP(i,n,m) for(int i=(n);i<(m);i++)

#include<iostream>
#include<cstring>
using namespace std;

int dect[24][6]={{2,1,5,0,4,3},{2,0,1,4,5,3},{2,4,0,5,1,3},{2,5,4,1,0,3},{4,2,5,0,3,1},{5,2,1,4,3,0},
					   {1,2,0,5,3,4},{0,2,4,1,3,5},{0,1,2,3,4,5},{4,0,2,3,5,1},{5,4,2,3,1,0},{1,5,2,3,0,4},
					   {5,1,3,2,4,0},{1,0,3,2,5,4},{0,4,3,2,1,5},{4,5,3,2,0,1},{1,3,5,0,2,4},{0,3,1,4,2,5},
					   {4,3,0,5,2,1},{5,3,4,1,2,0},{5,1,3,2,4,0},{1,0,3,2,5,4},{0,4,3,2,1,5},{4,5,3,2,0,1}};
string cube[4][24][6];
int n,ans,num;

int compare(string *T,string *P)
{
	int N=0;
	REP(i,0,6)
		if(T[i]!=P[i])
			N++;
	return N;
}

int main()
{
	while(cin>>n&&n!=0)
	{
		string C[6];
		REP(i,0,n)
		{
			REP(j,0,6)//可以优化
				cin>>C[j];
			REP(j,0,24)
				REP(k,0,6)
					cube[i][j][k]=C[dect[j][k]];
		}
		ans=0;
		REP(i,1,n)
		{
			num=6;
			REP(j,0,24)
				num=min(num,compare(cube[0][0],cube[i][j]));
			ans+=num;
		}
		cout<<ans<<endl;
	}
	return 0;
}
