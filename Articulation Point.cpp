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

#define pb push_back
#define INF 1<<28
#define SZ(a) a.size()
#define all(a) a.begin(),a.end()
#define m_p make_pair
#define pi 2*acos(0)
#define pb push_back
#define Clear(a,x) memset(a,x,sizeof a)
#define REP(i,n) for (i=0;i<n;i++)
#define REV(i,n) for (i=n;i>=0;i--)
#define FOR(i,p,k) for (i=p; i<k;i++)
#define ms(a,x) memset(a,x,sizeof a)

#define max_n 100000000
#define max_p 10000000

////bool operator<(const pq &x)const{return pw>x.pw;}};             //Min Priority_queue
////priority_queue<int,vi,greater<int> >Q;                          // Min Priority queue for One element.
////int rrr[]={1,0,-1,0};int ccc[]={0,1,0,-1};                      //4 Direction
//int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};  //8 direction
////int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
////int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1};           //Hexagonal Direction
////int month[]={31,28,31,30,31,30,31,31,30,31,30,31};

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector < int > vi;
typedef pair < int , int > paii;

/// 2^64 = 18446744073709551616
/// sqrt(2^64)= 4294967296

#define MAX 10009

int low[MAX] , tme[MAX] ;
bool color[MAX] , flag[MAX] ;
vi vec[MAX];
int node , edges , nob ;
int T;

void Articulation_Bridge(int node , int par )
{
    low[node] = tme[node] = T++;
    color[node] = true ;
    int subtree = 0;
    for(int i = 0 ; i < SZ(vec[node]) ; i++ )
    {
        int v = vec[node][i];
        if( v==par ) continue;

        if( !color[v] )
        {
             subtree++;
             Articulation_Bridge(v,node);
             low[node] = min(low[node],low[v]);
             if( low[v] >= tme[node] && par !=-1 ) flag[node] = true ;
        }
        else
        {
            low[node] = min(low[node],tme[v]);
        }

        if(subtree>1 && par==-1) flag[node]=true;
    }
    return ;
}

int main()
{
    int tc , TT = 0 ;
    cin>>tc;
    while(tc--)
    {
        int nob=0;
        T=1;
        ms(low,0); ms(tme,0); ms(color,false); ms(flag,false);
        cin>>node>>edges;
        for(int i = 0 ; i <= node+5 ; i++)  vec[i].clear();
        for( int i = 0 ; i < edges ; i++ )
        {
            int a , b ;
            cin>>a>>b;
            vec[a].pb(b); vec[b].pb(a);
        }

        Articulation_Bridge(1,-1);

        for( int i = 1 ; i <= node ; i++ )
        {
            if( flag[i] ) nob++;
        }
        printf("Case %d: %d\n" , ++TT , nob);
    }
    return 0 ;
}

