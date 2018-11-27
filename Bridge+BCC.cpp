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
typedef vector < int > vii;
typedef pair < int , int > paii;

template<class T1> void deb(T1 e){cout<<e<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;}

template < class T > inline T sqr( T n){ return n*n; }
template < class T > T Abs(T x) { return (x>0)?x:-x; }
template < class T > inline double LOG ( T a , T b ) { return ( log(a)/log(b)) ; }
template < class T > T power (T B ,T P){ return( P == 0) ? 1 : B * (power(B,(P-1))) ; }
template < class T > inline T gcd ( T a , T b ){ if ( a < 0 ) return gcd (-a,b);if ( b < 0 ) return gcd (a,-b);return (b==0)?a:gcd(b,a%b); }
template < class T > T BigMod ( T B , T P , T M ) { if ( P == 0 ) return 1;else if ( P % 2 == 0) return sqr((BigMod(B,P/2,M)))%M;else return (B%M) * (BigMod(B,P-1,M))%M; }
template < class T > T LCM ( T a , T b) { if ( a < 0 ) return LCM(-a,b);if ( b < 0 ) return LCM(a,-b);return (a*(b/GCD(a,b))); }

/// 2^64 = 18446744073709551616
/// sqrt(2^64)= 4294967296

#define MAX 10010

int low[MAX] , tme[MAX]  , comp[MAX] , compcount[MAX] ;
bool color[MAX];
vii vec[MAX];
int T , Components;
vector<paii>Bridge;
stack<int>S;

void Bridge_detection(int node , int par )
{
    low[node] = tme[node] = T++;
    color[node] = true;
    S.push(node);

    for( int i = 0 ; i < SZ(vec[node]) ; i++)
    {
        int v = vec[node][i];
        if(v==par) continue;
        if( !color[v] )
        {
            Bridge_detection(v,node);
            low[node] = min(low[node] , low[v]);
        }
        else
        {

            low[node] = min(low[node],tme[v]);
        }
    }

    if( low[node] == tme[node] )
    {
        while( SZ(S) )
        {
            int n = S.top(); S.pop();
            comp[n] = Components;
            if( n==node ) break;
        }
        Components++;
    }

    return ;
}

void BCC()
{
    ms(color,false); ms(low,0); ms(tme,0); ms(comp,0); ms(compcount,0); T = Components = 0 ;
    while( SZ(S) ) S.pop();
    Bridge_detection(0,-1);
    return ;
}

int main()
{
    int tc , TT=0;
    cin>>tc;
    while(tc--)
    {
        T=0;
        int node,edges;
        cin>>node>>edges;

        for( int i = 0 ; i < node+5 ; i++ ) vec[i].clear();
        for( int i = 0 ; i < edges ; i++ )
        {
            int a , b;
            cin>>a>>b;
            vec[a].pb(b); vec[b].pb(a);
        }

        BCC();

//        for( int i = 0 ; i < node ; i++ )
//        {
//            cout<<"I == "<<i<<" Comp no == "<<comp[i]<<endl;
//        }

        for( int i = 0 ; i < node  ; i++ )
        {
            for( int j = 0 ; j < (int) SZ(vec[i]) ; j++ )
            {
                int u , v ;
                u = i ;
                v = vec[i][j];

                if( comp[u] != comp[v] )
                {
                    compcount[comp[u]]++;
                    compcount[comp[v]]++;
                }
            }
        }

        int ans = 0 ;
        for( int i = 0 ; i < Components ; i++ ) if( compcount[i]==2 ) ans++;
        ans = (ans/2) + (ans%2);

      printf("Case %d: %d\n",++TT,ans);
    }
    return 0 ;
}

















