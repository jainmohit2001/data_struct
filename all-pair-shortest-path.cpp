/*
You are given 2 integers (N,M), N is the number of vertices, M is the number of edges. You'll also be given  ai, bi,wi  where ai and bi represents an edge from a vertex ai to a bi vertex  and wi respresents the weight of that edge.

Task is to find the shortest path from source vertex (vertex number 1) to all other vertices (vi) where (2<=i<=N).

Input:

First line contains two space separated integers(N,M)  Then M lines follow, each line has 3 space separated integers  ai,bi , wi.

Output:
Print the shortest distances from the source vertex (vertex number 1) to all other vertices (vi) where (2<=i<=N). Print "-1" in case the vertex "vi" can't be reached form the source vertex.
Leave a space between any 2 printed numbers.

Constraints:
1<=N<=10^4
1<=M<=10^6
1<=ai,bi<=N
1<=wi<=1000

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int dist[n+1][n+1];
    for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                dist[i][j] = INT_MAX;
            }
    }
    for(int i=0;i<m;i++){
        int ai,bi,wi;
        cin>>ai>>bi>>wi;
        dist[ai][bi] = wi;
    }
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                    if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j]){
                        dist[i][j] = min( dist[i][j], dist[i][k] + dist[k][j] );
                    }
        }
    }
}

    for (int i = 1; i <= n; i++)
    {
        for (int j = 2; j <= n; j++)
        {
            if (dist[i][j] == INT_MAX){
                cout<<-1<<" ";
            }
            else{
                cout<<dist[i][j]<<" ";
            }
        }
        cout<<endl;

    return 0;
}
}
