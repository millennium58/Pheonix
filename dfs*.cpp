
#include <bits/stdc++.h>

using namespace std;
const int N = 1e5+2;
std::vector<int>adj[N] ;
bool vis[N];

void dfs(int node){
    //preorder-first vis the node
    vis[node]=true;
    cout<<node<<" ";
    //iterate the node
    // vector<int>::iterator it;
    // for(it=adj[node].begin();it!=adj[node].end();it++){
    //     if(vis[*it]);
    //     else{
    //         dfs(*it);
    //     }
    // }
    for(int child:adj[node]){
        if(vis[child]);
        else{
            dfs(child);
        }
    }
}

int main()
{
   int n,x,y;
   cin>>n;
   for(int i=0;i<n;i++){
       vis[i]=false;
   }
   for(int i=0;i<n;i++){
       cin>>x>>y;
       adj[x].push_back(y);
       adj[y].push_back(x);
   }
   dfs(1);
}
