/*
Let G be a weighted graph. You need to find a connected cycle free subgraph of H of minimum cost.
The cost of a subgraph is defined as the sum of the weights of the edges present.

Input Output Specification
The first line of the input contains numbers n and m denoting the number of vertices and  edges in the graph.
The next m lines contain 3 numbers i,j and k indicating that the edge (i, j) is present and is of weight k.
The numbers i and j will be from 1 to n. The number k is a positive real number. You may assume that k and 1/k are less than 1 billion.
*/

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int findset(ll arr[], ll x){
	if(x!=arr[x]){
		arr[x]=findset(arr,arr[x]);
	}
	return arr[x];
}
void union_by_rank(ll arr[],ll ranks[],int a,int b){
	int lofa=findset(arr,a);
	int lofb=findset(arr,b);
	if(lofa!=lofb){
		if(ranks[lofa]<ranks[lofb]){
                swap(lofa,lofb);
		}
		arr[lofb]=lofa;
		if(ranks[lofa]==ranks[lofb]){
			ranks[lofa]++;
		}
	}
}
int main(){
	int n,m;
	cin>>n>>m;
	vector< pair<ll,pair<ll,ll> > > v;
	int x,y;
	ll w;
	for(int i=0;i<m;i++){
		cin>>x>>y>>w;
		v.push_back({w,{x,y}});
	}
	sort(v.begin(),v.end());
	ll arr[n+1],ranks[n+1];
	ll cost=1; //store min weight tree
	for(int i=0;i<n+1;i++){
		arr[i]=i; //make-set
		ranks[i]=0;
	}
	for(int i=0;i<v.size();i++){
		int rx = findset(arr,v[i].second.first);
		int ry = findset(arr,v[i].second.second);
		if(rx!=ry){ //only add edge if in different components (no cyle should be made)
			cost = cost+v[i].first;
			union_by_rank(arr,ranks,v[i].second.first,v[i].second.second);
		}
	}
	cout<<cost<<endl;
	return 0;
}
