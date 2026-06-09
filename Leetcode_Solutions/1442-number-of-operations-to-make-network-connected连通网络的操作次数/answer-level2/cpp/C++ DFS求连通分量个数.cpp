**解题思路：**

首先简单观察可以发现如果总的可用边数小于n-1就不能连通直接返回-1，那么也就是是说只要边数大于等于n-1就一定能全联通，这时候需要改变的边数，就是整个图的联通分量的个数cnt-1。

**dfs求联通分量个数：**

那么在这里用dfs找联通分量个数，每次dfs记录所有能访问节点，那么dfs次数就是图中联通分量的个数（这里使用邻接矩阵存图进行dfs）。

*在这里也可以选择直接使用并查集维护连通分量个数。*

```
class Solution {
public:
    bool vis[100010];
    vector<int> G[100010];
    void dfs(int s){
        for(auto to : G[s]){
            if(!vis[to]) {
                vis[to] = true;
                dfs(to);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        memset(vis,false, sizeof(vis));
        if(connections.size() < n - 1) return -1;
        else{
            for(auto it : connections){
                G[it[0]].push_back(it[1]),G[it[1]].push_back(it[0]);
            }
            int cnt = 0;
            for(int i = 0 ; i < n; i++){
                if(!vis[i]){
                    dfs(i);
                    cnt++;
                }
            }
            return cnt-1;
        }
    }
};
```
