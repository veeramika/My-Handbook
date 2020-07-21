///Check if cycle exists? if yes : ERROR
///As graph must be a DAG
///Queue will hold nodes with in-degree == 0
///Go on removing q front and decrement the in-degree of its neighbours
///KAHNS ALGORITHM : O(V+E)
#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int> >adj;
vector<int> vis;
bool err = 0;

int32_t main()
{
    int i,j,k,n,m;
    cin>>n>>m;
    adj.resize(n+1);
    vis.resize(n+1);
    vector<int> indegree(n+1,0);
    for(i = 0 ; i < m ; i++)
    {
        int x,y;
        cin>>x>>y;
        indegree[y]++;
        adj[x].push_back(y);  //it should be a DAG
    }

    queue<int> q;
    for(int u = 1 ; u <= n ; u++)
    {
        if(indegree[u]==0)
            {q.push(u);
            vis[u]=1;}
    }
    vector<int> toposort;
    while(!q.empty())
    {
      int u = q.front();
      for(int v : adj[u])
      {
          if(vis[v]==0)
          {
              indegree[v]--;           //as we will remove you and edges connected from it, so decrement the
          }                            //in-degree of its neighbours
          if(indegree[v]==0)
          {
              vis[v]=1;
              q.push(v);
          }
      }
      q.pop();
      toposort.push_back(u);
    }

    if(toposort.size() < n)
    {
        cout<<"ITS NOT A DAG!";
    }

    return 0;
}


