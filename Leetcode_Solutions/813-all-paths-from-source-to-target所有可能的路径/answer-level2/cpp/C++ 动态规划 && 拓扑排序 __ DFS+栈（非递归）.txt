## 思路一
动态规范+拓扑排序
```cpp
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        const int n = graph.size();
        vector<int> in(n, 0);
        for (const auto vv : graph) {
            for (const auto v : vv) {
                in[v]++;
            }
        }
        queue<int> qi;
        for (int i = 0; i < n; i++) {
            if (!in[i]) {
                qi.push(i);
            }
        }
        vector<vector<vector<int>>> dp(n); // dp[i]维护所有从0到i的路径
        dp[0] = {{0}};
        while (!qi.empty()) {
            auto node = qi.front();
            qi.pop();
            auto &vv = graph[node];
            for (auto v : vv) {
                in[v]--;
                if (!in[v]) {
                    qi.push(v);
                }
                for (auto &dpp : dp[node]) { // 遍历到达当前节点的所有路径方式
                    vector<int> temp = dpp;
                    temp.push_back(v); // 获取到目标点v的路径
                    dp[v].push_back(std::move(temp));
                }
            }
        }
        return std::move(dp[n - 1]);
    }
};
```

## 思路二
DFS+栈
```cpp
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ret;
        const int size = graph.size();
        vector<int> node_stack(size, 0);
        vector<int> index_stack(size, 0);
        int node_stack_len = 0;
        int index_stack_len = 0;

        node_stack[node_stack_len++] = 0;
        index_stack[index_stack_len++] = 0;
        while (graph[node_stack[node_stack_len - 1]].size() > 0) {
            node_stack[node_stack_len++]  = graph[node_stack[node_stack_len - 1]][0];
            index_stack[index_stack_len++] = 0;
        }
        while (node_stack_len > 0) {
            if (node_stack[node_stack_len - 1] == size - 1) {
                vector<int> temp(node_stack.begin(), node_stack.begin() + node_stack_len);
                ret.push_back(std::move(temp));
            }
            while (node_stack_len > 0 && index_stack[index_stack_len - 1] + 1 >= graph[node_stack[node_stack_len - 1]].size()) {
                node_stack_len--;
                index_stack_len--;
            }
            if (node_stack_len <= 0)
                break;
            //index_stack.top()++;
            index_stack[index_stack_len - 1]++;
            while (graph[node_stack[node_stack_len - 1]].size() > 0) {
                node_stack[node_stack_len++]  = graph[node_stack[node_stack_len - 1]][index_stack[index_stack_len - 1]];
                index_stack[index_stack_len++] = 0;
            }
        }
        return std::move(ret);
    }
};
```