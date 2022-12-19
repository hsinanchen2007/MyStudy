### 解题思路
主要理解逆序插入的必要性：
因为可能字母序小的路径不能走完全程，且这样的路径应该排在最终正确的路径的靠后部分，所以需要逆序插入。

### 代码

```cpp
class Solution {
public:
    using AdjMap = map<string, priority_queue<string, vector<string>, greater<string>>>;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        AdjMap adj;
        for (auto& v : tickets) {
            adj[v[0]].push(v[1]);
        }

        vector<string> res;
        dfs(adj, "JFK", res);
        reverse(res.begin(), res.end());
        return res;
    }

    void dfs(AdjMap& adj, string start, vector<string>& path) {
        while (adj.count(start) && !adj[start].empty()) {
            string next = adj[start].top();
            adj[start].pop();
            dfs(adj, next, path);
        }
        path.push_back(start);
    }
};
```