### 解题思路
关系优化存储到hash，然后BFS或者DFS， DFS用的递归会超时。

### 代码

```cpp
class Solution {
public:
    vector<int> ret;
    void dfs(map<int, vector<int>> relation, int kill) 
    {
        ret.push_back(kill);
        vector<int> children = relation[kill];
        for (auto child : children) {
            dfs(relation, child);
        }
    }
    void bfs(map<int, vector<int>> relation, int kill) 
    {
        queue<int> q;
        q.push(kill);
        while (!q.empty()) {
            vector<int> children = relation[q.front()];
            ret.push_back(q.front());
            q.pop();
            for (auto child : children) {
                q.push(child);
            }
        }
    }
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        map<int, vector<int>> relation;
        int n = pid.size();
        for (int i = 0; i < n; i++) {
            relation[ppid[i]].push_back(pid[i]);
        }
        // dfs(relation, kill);
        bfs(relation, kill);
        return ret;
    }
};
```