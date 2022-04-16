#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+2;
int parent[N];
int size[N];
//const int INF=1e9 ;

//disjoint set union

void make(int v){
    parent[v]=v;
    size[v]=1;
}

int find(int v){
    if(parent[v]==v)
        return parent[v];
    return parent[v]=find(parent[v]);
}

void Union(int a,int b){
    a=find(a);//will give root of a
    b=find(b);//will give root of b
    if(a!=b){
        //depeth comparision of both a & b
        if(size[a]<size[b]){
            swap(a,b);
        }
         parent[b]=a;//now b's root will be a
         size[a]+=size[b];
    }
}
int main(){
   int n,m,total_cost=0;cin>>n>>m;
   std::vector<pair<int,pair<int,int>>>edges  ;
   for(int i=0;i<m;i++){
       int u,v,wt;
       cin>>u>>v>>wt;
       edges.push_back({wt,{u,v}});
   }
   sort(edges.begin(),edges.end());
   for(int i=1;i<=n;i++){
       make(i);
   }
   for(auto &edge:edges){
       int wt=edge.first;
       int u=edge.second.first;
       int v=edge.second.second;

       if(find(u)==find(v)){
           continue;
       }
           Union(u,v);
           total_cost+=wt;
           cout<<u<<" "<<v<<endl;
   }
   cout<<total_cost<<endl;
}
