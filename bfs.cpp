/*
BFS:
Question:
Given a 2d grid size n X m of '1's (land) and '0's (water),count the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
You may assume all four edges of the grid are all surrounded by water.
*/

#include <bits/stdc++.h>
using namespace std;


int main(){
	int n,m;
	cin>>n>>m;
	int grid[n][m];
	vector< pair<int,int> > edge;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>grid[i][j];
			if(grid[i][j]){
				edge.push_back({i,j});
			}
		}
	}
	int Size= edge.size();
	int visited[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			visited[i][j]=0;
		}
	}
	int ans=0;
	for(int i=0;i<Size;i++){
		vector< pair<int,int >> v;
		int x = edge[i].first;
		int y = edge[i].second;
		if(visited[x][y]==0){
			ans++;
			v.push_back({x,y});
			while(v.size() != 0){
				pair<int,int> val= v.back();
				v.pop_back();
				int l= val.first;
				int r= val.second;
				visited[l][r]=1;
				if(l-1>=0 && grid[l-1][r] && !visited[l-1][r]) v.push_back({l-1,r});
				if(l+1<n && grid[l+1][r] && !visited[l+1][r]) v.push_back({l+1,r});
				if(r-1>=0 && grid[l][r-1] && !visited[l][r-1]) v.push_back({l,r-1});
				if(r+1<m && grid[l][r+1] && !visited[l][r+1]) v.push_back({l,r+1});
			}

		}
	}
	cout<<ans;

	return 0;
}
