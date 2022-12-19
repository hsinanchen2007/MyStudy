### 解题思路
一个n个顶点的连通图，至少需要n-1条边。所以当边数小于顶点数-1，则无法连通；否则就可以连通。
用dfs计算连通分量的个数，当有m个连通分量时，需要至少操作m-1条边形成连通图。

### 代码

```cpp
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        int edgeCounts=connections.size();
        if(n-1>edgeCounts) return -1;
        vector<vector<int>> adj(n);
        for(int i=0;i<edgeCounts;i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        int part=0;
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++)
        {
            if(!visited[i]) 
            {
                part++;
                dfs(connections,adj,i,visited,edgeCounts);

            }
        }
        if(part==1){ return 0;}
        else {return --part;}
    }
    void dfs(vector<vector<int>>& connections,vector<vector<int>>& adj,int i,vector<bool>& visited,int edgeCounts)
    {
        visited[i]=true;
        for(int j=0;j<adj[i].size();j++)
        {
            if(!visited[adj[i][j]]) dfs(connections,adj,adj[i][j],visited,edgeCounts);
        }
    }

};
```