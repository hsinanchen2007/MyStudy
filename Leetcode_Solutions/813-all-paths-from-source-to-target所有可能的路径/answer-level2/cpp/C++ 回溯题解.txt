### 解题思路
朴素回溯算法即可

### 代码

```cpp
class Solution {
public:
    void backtrace(const vector<vector<int> >& graph, int n, int i, vector<int>& path, vector<vector<int> >& res) {
        if (i == n - 1) {
            res.push_back(path);
            return;
        }
        for (auto j : graph[i]) {
            path.push_back(j);
            backtrace(graph, n, j, path, res);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int> > res;
        vector<int> path{0};
        backtrace(graph, graph.size(), 0, path, res);
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/d64200c5574be3c42557a9e8aab7775515a7d6caf24ac4700841fa1923b6e042-image.png)
