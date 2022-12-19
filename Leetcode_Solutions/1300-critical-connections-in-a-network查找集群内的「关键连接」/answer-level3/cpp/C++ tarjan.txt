### 解题思路
建议先观看一下视频
https://www.bilibili.com/video/av83583621?p=5

### 代码

```cpp
class Solution {
public:
    vector<int> low;
    vector<int> dfn;
    vector<vector<int>> edges;
    vector<vector<int>> ret;
    vector<bool> visited;
    int time;
    
    void tarjan(int node, int parent) {
        time++;
        low[node] = time;
        dfn[node] = time;
        visited[node] = true;
        
        for (auto e : edges[node]) {
            // 访问node的每个邻接点
            
            if (e == parent) {
                continue;
            }
            if (!visited[e]) {
                // 没被访问
                tarjan(e, node);
                
                low[node] = min(low[e], low[node]);
                
                if (low[e] > dfn[node]) {
                    // node和e不在一个强联通分量里
                    ret.push_back({node, e});
                }
            } else {
                low[node] = min(low[node], dfn[e]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        low = vector<int>(n, -1);
        dfn = vector<int>(n, -1);
        visited = vector<bool>(n, false);
        edges = vector<vector<int>>(n);
        time = 0;
        for (auto edge : connections) {
            edges[edge[0]].push_back(edge[1]);
            edges[edge[1]].push_back(edge[0]);
        }
        
        tarjan(0, -1);
        return ret;
    }
};
```