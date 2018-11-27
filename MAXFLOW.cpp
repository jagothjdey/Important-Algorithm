#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<string>
#include<sstream>
#include<ctype.h>
#include<vector>
#include<map>
#include<queue>
#include<math.h>
#include<algorithm>
#include<set>

#define pb push_back
#define PI acos(-1.0)
#define SZ(a) (int)a.size()
#define csprnt printf("Case %d: ", cas++);
#define EPS 1e-9
#define MAX 100010
#define INF (1<<30)
#define pii pair<int, int>

using namespace std;

string arr[] = {"XXL", "XL", "L", "M", "S", "XS"};
map<string, int>mp;
int source, sink, dist[60][60], par[60], flow;
vector<int>adj[60];

bool aug_path()
{
    int i, u, v;
    queue<int>Q;
    Q.push(source);
    memset(par, -1, sizeof par);
    while(!Q.empty())
    {
        u = Q.front(); Q.pop();
        for(i=0;i<SZ(adj[u]);i++)
        {
            v = adj[u][i];
            if(par[v]==-1 && dist[u][v]>0)
            {
                par[v] = u;
                Q.push(v);
                if(v==sink)
                    return true;
            }
        }
    }
    return false;
}

void path_upd(int v)
{
    int u = par[v];
    flow = min(dist[u][v], flow);
    if(u!=source) path_upd(u);
    dist[u][v]-=flow;
    dist[v][u]+=flow;
    return;
}

int maxflow()
{
    int ret=0;
    while(aug_path())
    {
        flow=INF;
        path_upd(sink);
        ret+=flow;
    }
    return ret;
}

int main()
{
    int t, cas=1;
    for(int i=0;i<6;i++)
        mp[arr[i]]=i+1;
    scanf("%d", &t);
    while(t--)
    {
        int n, m, i, j, k, now;
        string s1, s2;
        memset(dist, 0, sizeof dist);
        scanf("%d%d", &n, &m);
        source=0, sink=59;
        for(i=1;i<=6;i++)
        {
            adj[source].pb(i);
            adj[i].pb(source);
            dist[source][i] = n;
        }
        for(i=0;i<m;i++)
        {
            now = i+7;
            cin>>s1>>s2;
            adj[mp[s1]].pb(now);
            adj[now].pb(mp[s1]);
            dist[mp[s1]][now] = 1;

            adj[mp[s2]].pb(now);
            adj[now].pb(mp[s2]);
            dist[mp[s2]][now] = 1;

            adj[now].pb(sink);
            adj[sink].pb(now);
            dist[now][sink] = 1;
        }
        int ans = maxflow();
        csprnt;
        if(ans==m)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

