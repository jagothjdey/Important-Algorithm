
#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<string>
#include<vector>
#include<cstring>
#include<map>

#define pc(a) __builtin_popcount(a)
#define pb push_back
#define INF 1<<28
#define SZ(a) a.size()
#define all(a) a.begin(),a.end()
#define pb push_back
#define m_p make_pair
#define pi 2*acos(0)
#define ms(a,x) memset(a,x,sizeof a)

#define REP(i,n) for (i=0;i<n;i++)
#define REV(i,n) for (i=n;i>=0;i--)
#define FOREACH(it,x) for(__typeof((x).begin()) it=(x.begin()); it!=(x).end(); ++it)
#define FOR(i,p,k) for (i=p; i<k;i++)

#define Sort(a) sort(a.begin(),a.end())

using namespace std;

#define MAX 10009

vector<int>vec[MAX];
bool color[MAX];
int tme[MAX] , low[MAX];
int T;
vector< pair<int,int> > vbri;

void dfs( int node , int par )
{
    low[node] = tme[node] = T++;
    color[node] = true;
    for( int i = 0 ; i < SZ(vec[node]) ; i++ )
    {
        int v = vec[node][i];
        if( v==par ) continue ;
        if( !color[v] )
         {
             dfs(v,node);
             low[node] = min(low[node],low[v]);
             if( low[v] > tme[node] )
             {
                 vbri.pb(m_p(min(node,v),max(node,v)));
             }
         }
         else
         {
             low[node] = min(low[node],tme[v]);
         }
    }
    return ;
}

int main()
{
    int tc,t=0;
    scanf(" %d",&tc);
    while(tc--)
    {
        int node;
        scanf(" %d",&node);
        ms(low,0); ms(tme,0); ms(color,false); vbri.clear(); for ( int i = 0 ; i < node+10 ; i++ ) vec[i].clear();
        int n,e;

        for( int i = 0 ; i < node ; i++ )
        {
            scanf(" %d (%d)",&n,&e);
            for( int j = 0 ; j < e ; j++ )
            {
                int x; scanf(" %d",&x);
                vec[n].pb(x); vec[x].pb(n);
            }
        }

        T = 1 ;

        for( int i = 0 ; i < node ; i++ )
        {
            if( !color[i] ) dfs(i,-1);
        }

        sort(vbri.begin(),vbri.end());
        printf("Case %d:\n",++t);
        printf("%d critical links\n",SZ(vbri));
        for( int i = 0 ; i < SZ(vbri) ; i++ )
        {
            printf("%d - %d\n",vbri[i].first,vbri[i].second);
        }

    }
    return 0 ;
}
