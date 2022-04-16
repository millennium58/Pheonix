#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+2;
int parent[N];
int size[N];
const int INF=1e9 ;

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
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        make(i);
    }
    while(k--){
        int u,v;cin>>u>>v;
        Union(u,v);
    }
    int cnnected_ct=0;
    for(int i=1;i<=n;i++){
        if(find(i)==i){
            cnnected_ct++;
        }
    }
    cout<<cnnected_ct<<endl;
}
