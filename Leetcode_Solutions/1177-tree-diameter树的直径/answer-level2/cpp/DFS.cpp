### 解题思路一

DFS：

1. 假定0号节点为 root；
2. 从 root 节点出发做一次DFS，最远的节点记为 P1；
3. 从 P1 节点出发做一次DFS，最远的节点记为 P2，P1和P2之间的距离即为树的直径。

### 代码

```cpp
class Solution {
private:
    vector<vector<int>> graph;
    vector<bool> visited;
public:
    int treeDiameter(vector<vector<int>>& edges) {
        // build graph
        graph.resize(10000);
        visited.resize(10000);
        for(auto e: edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        pair<int, int> p1, p2;
        p1 = { -1, 0 };
        dfs(0, 0, p1);
        
        // cout << p1.first << endl;
        
        visited.assign(10000, false);
        p2 = { -1, 0 };
        dfs(p1.first, 0, p2);
        
        // cout << p2.first << endl;
        
        return p2.second;
    }
    
    void dfs(int u, int depth, pair<int, int>& p) {
        visited[u] = true;
        if(depth > p.second) {
            p.second = depth;
            p.first = u;
        }
        
        for(int v: graph[u]) {
            if(!visited[v]) {
                dfs(v, depth + 1, p);
            }
        }
    }
};
```