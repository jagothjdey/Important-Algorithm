
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
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>

#define pb push_back
#define INF 1<<28
#define sz(a) a.size()
#define all(a) (a.begin(),a.end())
#define mx 100100

using namespace std;

bool color[mx];
vector < int > vec[mx] , first;

void dfs ( int start)
{
//    cout<<"FOR "<<start<<endl;

    color[start] = true;
    for ( int i = 0 ; i < vec[start].size(); i++)
    {
        int var = vec[start][i];

        if ( !color[var] )
        {
//            cout<<var<<endl;
            dfs(var);
        }
    }

    return ;
}

int main()
{
    int tc,T=0;
    cin>>tc;
    while(tc--)
    {
        int node,edges;
        cin>>node>>edges;

        memset ( color , false , sizeof color);

        for ( int i = 1 ; i<= edges ; i++)
        {
            int a,b;
            cin>>a>>b;

            vec[a].push_back(b);
        }

        int count = 0 ;

        for ( int i = 1 ; i<= node ; i++)
        {
            if ( !color[i] )
            {
//                cout<<"I HAVE TO PUSH = "<<i<<endl;
                ++count;
                first.push_back(i);
//                cout<<"PUHSING = "<<i<<endl;
                dfs(i);
            }
        }

        int count_ulta = 0;

        reverse(first.begin() , first.end() );

        memset ( color , false , sizeof color);
        for ( int i = 0 ; i < first.size() ; i++)
        {
            if ( !color[first[i]] )
            {
                ++count_ulta;
                dfs(first[i]);
            }
        }

//        printf("Case %d: %d\n",++T,min(count,count_ulta));
        printf("Case %d: %d\n",++T,min(count,count_ulta));

        for ( int i = 0 ; i <= node ; i++) vec[i].clear();
        first.clear();
    }
    return 0;
}
