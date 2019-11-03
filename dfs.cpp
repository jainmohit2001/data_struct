/*
A graph is said to be disconnected if it is not connected, i.e. if two nodes exist in the graph such that there is no edge in between those nodes.
In an undirected graph, a connected component is a set of vertices in a graph that are linked to each other by paths.

Given A graph, find the total number of disconnected components in it.

INPUT:
First line contains n = number of nodes.
Second lines contains e = number of edges.
The next e line contains 2 numbers x and y, in which x and y are connected by an edge.

OUTPUT:
Total number of disconnected components

Constraints:
1<=n<=10^5
1<=e<=10^5

*/

#include <bits/stdc++.h>

    using namespace std;


    void dfs(vector <int> adj[],bool visited[],int s) {
        visited[s] = true;
        for(int i = 0;i < adj[s].size();i++)    {
         if(visited[adj[s][i]] == false){
             dfs(adj,visited,adj[s][i]);
         }
        }
    }

    int main() {
        int nodes, edges;
        cin >> nodes>>edges;
        vector <int> adj[nodes+1];
        bool visited[nodes+1];
        int x, y, connectedComponents = 0;

        for(int i = 0;i < edges;i++) {
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        for(int i = 1;i <= nodes;i++){
            visited[i] = false;
        }
        for(int i = 1;i <= nodes;i++) {
         if(visited[i] == false)     {
             dfs(adj,visited,i);
             connectedComponents++;
         }
        }
        cout << "Number of connected components: " << connectedComponents << endl;
        return 0;
    }
