```
class Solution {
public:
    vector<int> dfn;
    vector<int> low;
    vector<bool> visited;
    vector<vector<int> > g;
    int rank;
    void tarjan(const vector<vector<int> >& g, int i, int p, vector<vector<int> >& res) {
        dfn[i] = low[i] = ++rank;
        visited[i] = true;
        for (auto j : g[i]) {
            if (j == p) continue;
            if (!visited[j]) {
                tarjan(g, j, i, res);
                low[i] = min(low[i], low[j]);
                if (low[j] > dfn[i]) res.push_back({i, j});
            } else {
                low[i] = min(low[i], low[j]);
            }
        }
    }
    vector<vector<int> > criticalConnections(int n, vector<vector<int> >& connections) {
    	rank = 0;
    	dfn.resize(n);
    	low.resize(n);
    	visited.resize(n);
        g.resize(n);
    	for (int i = 0; i < n; ++i) visited[i] = false; 
        for (auto& e : connections) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        vector<vector<int> > res;
        tarjan(g, 0, -1, res);
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/e1ce1f8675202036cafa282011fb64276ac82e88aa64ab774ba6ac3bf22efb85-image.png)
