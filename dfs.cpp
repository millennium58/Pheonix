#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+2;
bool vis[N];
vector<int>adj[N];

void dfs(int node){
    //preorder
    vis[node]=true;
    cout<<node<<" ";

    //inorder
    vector<int> :: iterator it;
    for(it=adj[node].begin();it!=adj[node].end();it++){
        if(vis[*it]);
        else{
            dfs(*it);
        }
    }
    //postorder

}

int main()
{
    int n,m;cin>>n>>m;
    int x,y;

     for(int i=0;i<n;i++){
       vis[i]=false;
    }
    for(int i=0;i<m;i++){
       cin>>x>>y;
       adj[x].push_back(y);
       adj[y].push_back(x);
    }

    dfs(3);

}
