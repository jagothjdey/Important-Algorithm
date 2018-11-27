#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <list>
#include <set>
#include <cmath>
#include <cstring>

#include <stdio.h>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include <iomanip>
#include <ctime>

using namespace std;

//Type Definition
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi>vvi;
typedef vector<string> vs;
typedef map<string,int> msi;
typedef map<int,int>mii;

#define INF (1<<28)
#define SIZE 210
#define ERR 1e-9
#define PI 3.141592653589793

#define REP(i,n) for (i=0;i<n;i++)
#define FOR(i,p,k) for (i=p; i<k;i++)
#define FOREACH(it,x) for(__typeof((x).begin()) it=(x.begin()); it!=(x).end(); ++it)

#define Sort(x) sort(x.begin(),x.end())
#define Reverse(x) reverse(x.begin(),x.end())
#define MP(a,b) make_pair(a,b)
#define Clear(x,with) memset(x,with,sizeof(x))
#define SZ(x) (int)x.size()
#define pb push_back
#define popcount(i) __builtin_popcount(i)
#define gcd(a,b)    __gcd(a,b)
#define lcm(a,b) ((a)*((b)/gcd(a,b)))
#define two(X) (1<<(X))
#define twoL(X) (((ll)(1))<<(X))
#define setBit(mask,i) (mask|two(i))
#define contain(S,X) (((S)&two(X))!=0)
#define X first
#define Y second
#define CS c_str()
#define EQ(a,b) (fabs(a-b)<ERR)

//For debugging
template<class T1> void debug(T1 e)
{
    cout<<e<<endl;
}
template<class T1,class T2> void debug(T1 e1,T2 e2)
{
    cout<<e1<<"\t"<<e2<<endl;
}
template<class T1,class T2,class T3> void debug(T1 e1,T2 e2,T3 e3)
{
    cout<<e1<<"\t"<<e2<<"\t"<<e3<<endl;
}
template<class T1,class T2,class T3,class T4> void debug(T1 e1,T2 e2,T3 e3,T4 e4)
{
    cout<<e1<<"\t"<<e2<<"\t"<<e3<<"\t"<<e4<<endl;
}
template<class T1,class T2,class T3,class T4,class T5> void debug(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5)
{
    cout<<e1<<"\t"<<e2<<"\t"<<e3<<"\t"<<e4<<"\t"<<e5<<endl;
}
template<class T1,class T2,class T3,class T4,class T5,class T6> void debug(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6)
{
    cout<<e1<<"\t"<<e2<<"\t"<<e3<<"\t"<<e4<<"\t"<<e5<<"\t"<<e6<<endl;
}
template<class T> void debug(vector< vector<T> > e,int row,int col)
{
    int i,j;
    REP(i,row)
    {
        REP(j,col) cout<<e[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}
template<class T> void debug(vector< basic_string<T> > e,int row,int col)
{
    int i,j;
    REP(i,row)
    {
        REP(j,col) cout<<e[i][j];
        cout<<endl;
    }
    cout<<endl;
}
template<class T> void debug(T e[SIZE][SIZE],int row,int col)
{
    int i,j;
    REP(i,row)
    {
        REP(j,col) cout<<e[i][j]<<" ";
        cout<<endl;
    }
}

//Important Functions
template<class T> void setmax(T &a, T b)
{
    if(a < b) a = b;
}
template<class T> void setmin(T &a, T b)
{
    if(b < a) a = b;
}
template<class T> T Abs(T x)
{
    return x > 0 ? x : -x;
}
template<class T> inline T sqr(T x)
{
    return x*x;
}
template<class T> inline T Mod(T n,T m)
{
    return (n%m+m)%m;   //For Positive Negative No.
}
template<class T> string toString(T n)
{
    ostringstream oss;
    oss<<n;
    oss.flush();
    return oss.str();
}
int toInt(string s)
{
    int r=0;
    istringstream sin(s);
    sin>>r;
    return r;
}
bool isVowel(char ch)
{
    ch=tolower(ch);
    if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')return true;
    return false;
}
bool isUpper(char c)
{
    return c>='A' && c<='Z';
}
bool isLower(char c)
{
    return c>='a' && c<='z';
}
ll Pow(ll B,ll P)
{
    ll R=1;
    while(P>0)
    {
        if(P%2==1)	R=(R*B);
        P/=2;
        B=(B*B);
    }
    return R;
}
int BigMod(ll B,ll P,ll M)
{
    ll R=1;
    while(P>0)
    {
        if(P%2==1)
        {
            R=(R*B)%M;
        }
        P/=2;
        B=(B*B)%M;
    }
    return (int)R;
}
void binprint(ll mask,ll n)
{
    ll i;
    string s="";
    do
    {
        s+=(mask%2+'0');
        mask/=2;
    }
    while(mask);
    Reverse(s);
    s=string(max(n-SZ(s),0LL),'0')+s;
    for(i=SZ(s)-n; i<SZ(s); i++) printf("%c",s[i]);
    printf("\n");
}
void ASCII_Chart()
{
    int i,j,k;
    printf("ASCII Chart:(30-129)\n");
    FOR(i,30,50)
    {
        REP(j,5)
        {
            k=i+j*20;
            printf("%3d---> '%c'   ",k,k);
        }
        printf("\n");
    }
}


//int month[]={-1,31,28,31,30,31,30,31,31,30,31,30,31};  //Not Leap Year
//string monthName[]={"","January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
//string dayName[]={"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={-1,-1,+0,+1,+1,+0};int dy[]={-1,+1,+2,+1,-1,-2}; //Hexagonal Direction

//#include<conio.h> //for using getch();

//struct pq{ int cost,node; pq(int _cost=0,int _node=0){cost=_cost;node=_node;}bool operator<(const pq &b)const {return cost>b.cost;}}; // Min Priority Queue
//bool comp(pq a,pq b){ return a.cost < b.cost;} //Asc Sort by cost

#define MAXN 210

int cap[SIZE][SIZE],mat[SIZE][SIZE],par[MAXN],source,sink,flow,nodes,edges,x[MAXN],y[MAXN],peng[MAXN];
vi adj[MAXN];

void addedge(int u,int v,int cost)
{
    adj[u].pb(v);
    adj[v].pb(u);
    cap[u][v]=cost;
}

bool Augment_Path()
{
    int i,u,v;
    queue<int>Q;

    Clear(par,-1);
    par[source]=-2;
    Q.push(source);

    while(!Q.empty())
    {
        u=Q.front();
        Q.pop();

        REP(i,SZ(adj[u]))
        {
            v=adj[u][i];
            if(par[v]==-1 && cap[u][v]>0)
            {
                par[v]=u;
                if(v!=sink) Q.push(v);
            }
        }
    }
    if( par[sink]!=-1 ) return true ;
    else return false;
}

void Network_Update(int v)
{
    int u=par[v];
    if(u>=0)
    {
        flow=min(flow,cap[u][v]);
        Network_Update(u);
        cap[u][v]-=flow;
        cap[v][u]+=flow;
    }
}

int MaxFlow()
{
    int i,ans=0;

    while(Augment_Path()==true )
    {
        for( int i = 0 ; i < nodes ; i++ )
        {
            if( par[i]!=-1 && cap[i][sink]>0)
            {
                flow=INF;
                par[sink]=i;
                Network_Update(sink);
                ans+=flow;
            }
        }
    }
    return ans;
}

int main()
{
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
    //ios_base::sync_with_stdio(false);

    int i,j,k,test,Case=1,u,v,val,N,sum;
    double Dist,d;
    vi ans;

    scanf("%d",&test);

    while(test--)
    {
        scanf("%d %lf",&N,&Dist);

        REP(i,N+N+3) adj[i].clear();
        Clear(cap,0);
        ans.clear();

        sum=0;
        REP(i,N)
        {
            scanf("%d %d %d %d",&x[i],&y[i],&peng[i],&val);
            sum+=peng[i];
            u=i+1;
            v=u+N;
            addedge(u,v,val);
           // cout<<"EDGE ->"<<u<<" "<<v<<" "<<val<<endl;
        }
        source=0;
        nodes=N+N+1;
        REP(i,N)
        {
            addedge(source,i+1,peng[i]);
           // cout<<"EDGE ->"<<source<<" "<<i+1<<" "<<peng[i]<<endl;
        }
        REP(i,N)
        {
            REP(j,N)
            {
                if(i==j) continue;
                d=sqrt(sqr(x[i]-x[j]+0.0)+sqr(y[i]-y[j]+0.0));
                if(d<=Dist)
                {
                    u=i+1+N;
                    v=j+1;
                    addedge(u,v,INF);
                    //cout<<"EDGE ->"<<u<<" "<<v<<" "<<"INF"<<endl;
                }
            }
        }
        REP(i,N)
        {
            REP(j,nodes)
              REP(k,nodes)
               mat[j][k]=cap[j][k];


            sink=i+1;
            val=MaxFlow();
            //debug(val);
            if(val==sum)
                ans.pb(i);
            REP(j,nodes) REP(k,nodes) cap[j][k]=mat[j][k];
        }
        if(SZ(ans)==0)
            printf("Case %d: -1\n",Case++);
        else
        {
            printf("Case %d:",Case++);
            REP(i,SZ(ans))
            printf(" %d",ans[i]);
            printf("\n");
        }
    }

    return 0;
}
