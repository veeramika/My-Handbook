///Check if cycle exists? if yes : ERROR
///As graph must be a DAG
/// O(V+E)
#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int> >adj;
vector<int> vis;
bool err = 0;
stack<int> s;
void dfs(int u)
{
    vis[u] = 1; //grey
    for(auto v : adj[u])
    {
        if(vis[v] == 1)
        {
            err = 1;
            return;
        }
        if(vis[v] == 0)
            dfs(v);
    }
    vis[u] = 2; //black
    s.push(u);  //when a node is finished, put in stack
}

int32_t main()
{
    int i,j,k,n,m;
    cin>>n>>m;
    adj.resize(n+1);
    vis.resize(n+1);
    for(i = 0 ; i < m ; i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);  //it should be a DAG
    }

    for(int u = 1 ; u <= n ; u++)
    {
        if(err)
        {
            cout<<"ITS NOT A DAG!";
            return 0;
        }
        if(vis[u]==0)
            dfs(u);
    }
    vector<int> toposort;
    while(!s.empty())
    {
       toposort.push_back(s.top());
       cout<<s.top()<<" ";
       s.pop();
    }

    return 0;
}

