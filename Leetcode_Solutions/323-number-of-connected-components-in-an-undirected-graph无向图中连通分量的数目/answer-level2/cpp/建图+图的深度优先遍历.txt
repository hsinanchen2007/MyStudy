### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {

        // adjacency list 邻接表 ...
        unordered_map<int, vector<int>> adjList;
        for (auto& e : edges) {
            adjList[e[0]].emplace_back(e[1]);
            adjList[e[1]].emplace_back(e[0]);
        }

        vector<bool> visited(n, false); // 访问标记 vector
        // Depth First Search
        function<void(int)> dfs = [&](int n) {
            if (visited[n]) return;
            visited[n] = true;
            for (int x : adjList[n]) dfs(x);
        };

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                ans++;
                dfs(i);
            }
        }

        return ans;
    }
};
```