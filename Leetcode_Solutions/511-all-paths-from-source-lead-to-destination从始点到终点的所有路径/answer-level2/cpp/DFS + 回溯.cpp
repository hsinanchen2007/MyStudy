### 解题思路

执行用时 :60 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗 :27 MB, 在所有 C++ 提交中击败了40.35%的用户

### 代码

```cpp
class Solution {
private:
    vector<vector<int>> graph;
    vector<bool> visited;
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        // init graph
        graph.resize(n);
        visited.resize(n);
        for(auto& e: edges) {
            graph[e[0]].push_back(e[1]);
        }
        visited[source] = true;
        return dfs(source, destination);
    }
    
    bool dfs(int u, int dest) {
        if(graph[u].size() == 0)
            return u == dest;       // 最终结束于目标终点
        for(int v: graph[u]) {
            if(visited[v])          // 有环
                return false;
            visited[v] = true;
            if(!dfs(v, dest))       // 避免走回头路
                return false;
            visited[v] = false;     // 回溯
        }
        return true;                // 所有邻接顶点可达终点
    }
};
```