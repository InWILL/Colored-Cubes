#define REP(i,n,m) for(int i=(n);i<(m);i++)

#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int dect[24][6]={{2,1,5,0,4,3},{2,0,1,4,5,3},{2,4,0,5,1,3},{2,5,4,1,0,3},{4,2,5,0,3,1},{5,2,1,4,3,0},
					   {1,2,0,5,3,4},{0,2,4,1,3,5},{0,1,2,3,4,5},{4,0,2,3,5,1},{5,4,2,3,1,0},{1,5,2,3,0,4},
					   {5,1,3,2,4,0},{1,0,3,2,5,4},{0,4,3,2,1,5},{4,5,3,2,0,1},{3,4,5,0,1,2},{3,5,1,4,0,2},
					   {3,1,0,5,4,2},{3,0,4,1,5,2},{1,3,5,0,2,4},{0,3,1,4,2,5},{4,3,0,5,2,1},{5,3,4,1,2,0}};
int n,ans,tot,num,r[4],cube[4][6],color[4][6];

vector<string> names;
int ID(string s)
{
	int n=names.size();
	REP(i,0,n)
		if(names[i]==s) return i;
	names.push_back(s);
	return n;
}

void check()
{
	REP(i,0,4) REP(j,0,6)
		color[i][j]=cube[i][dect[r[i]][j]];
	int tot=0;
	REP(i,0,6)
	{
		int cnt[24];
		memset(cnt,0,sizeof(cnt));
		int maxface=0;
		REP(j,0,n)
			maxface=max(maxface,++cnt[color[j][i]]);
		tot+=n-maxface;
	}
	ans=min(ans,tot);
}

void dfs(int d)
{
	if(d==n) check();
	else REP(i,0,24)
	{
		r[d]=i;
		dfs(d+1);
	}
}

int main()
{
	while(cin>>n&&n!=0)
	{
		names.clear();
		REP(i,0,n)
			REP(j,0,6)
			{
				string s;
				cin>>s;
				cube[i][j]=ID(s);
			}
		ans=n*6;
		r[0]=0;
		dfs(1);
		cout<<ans<<endl;
	}
	return 0;
}
