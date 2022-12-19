### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
        // adjacency list 对于稀疏图用邻接表比较好， 稠密图用邻接矩阵比较好。
        unordered_map<int, vector<int>> adjList;
        for (auto& v : graph) {
            if (v[0] != v[1] && find(adjList[v[0]].begin(), 
                    adjList[v[0]].end(), v[1]) == adjList[v[0]].end()) {

                adjList[v[0]].emplace_back(v[1]);
            }
        }

        vector<bool> visited(n, false); 

        queue<int> q;
        q.emplace(start);

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            
            if (cur == target)
                return true;

            for (int n : adjList[cur]) {
                if (!visited[n]) {
                    visited[n] = true;
                    q.emplace(n);
                }
            }
        }

        return false;
    }
};
```