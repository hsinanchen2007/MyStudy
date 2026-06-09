```
class Solution {
public:
    void dfs(const vector<vector<int> >& graph, vector<bool>& visited, int i, vector<int>& status) {
        if (status[i] != 0) return;
        status[i] = -1;
        for (auto j : graph[i]) {
            // has loop
            if (visited[j]) return;
            visited[j] = true;
            dfs(graph, visited, j, status);
            visited[j] = false;
            // hit invalid neighor nodes
            if (status[j] == -1) return;
        }
        // is a safe node
        status[i] = 1;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int N = graph.size();
        vector<bool> visited(N, false);
        vector<int> status(N, 0);
        for (int i = 0; i < N; ++i) {
            dfs(graph, visited, i, status);
        }
        vector<int> res;
        for (int i = 0; i < N; ++i) {
            if (status[i] == 1) res.push_back(i);
        }
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/4f15bbc89190e8a477604df35a14e07f2eee84925d939d2391a163e3e00c012a-image.png)


