#include<bits/stdc++.h>
using namespace std;

const int inf=1e7;

int main(){
    int n,e;cin>>n>>e;
    std::vector<int>dist(n+1,inf) ;
    vector<vector<pair<int,int>>>graph(n+1);
    for(int i=0;i<e;i++){
        int u,v,wt;cin>>u>>v>>wt;
        graph[u].push_back({v,wt});
        graph[v].push_back({u,wt});
    }
    int source ;cin>>source;
    dist[source]=0;
    set<pair<int,int>>s;
    s.insert({0,source});//{dist,source}
    while(!s.empty()){
         auto x =*(s.begin());
         s.erase(x);
         for(auto it:graph[x.second]){
              if(dist[it.first]>dist[x.second]+it.second ){
                  s.erase({dist[it.first],it.first});
                  dist[it.first]=dist[x.second]+it.second;
                  s.insert({dist[it.first],it.first});
              }
         }
    }
    for(int i=1;i<=n;i++){
        if(dist[i]<inf){
            cout<<dist[i]<<" ";
        }
        else{
            cout<<-1;
        }
    }

}
