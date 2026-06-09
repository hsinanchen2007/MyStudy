颜色交替深度优先搜索，不断更新最短距离
```
class Solution {
public:
    const int INF = 1e8;
    void dfs(vector<vector<vector<int> > >& g, int col, int i, vector<vector<int> >& res) {
        for (auto j : g[col][i]) {
            if (res[i][col] + 1 < res[j][!col]) {
                res[j][!col] = res[i][col] + 1;
                dfs(g, !col, j, res);
            }
        }
    }
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        vector<vector<int> > rg(n);
        vector<vector<int> > bg(n);
        for (auto& e : red_edges) rg[e[0]].push_back(e[1]);
        for (auto& e : blue_edges) bg[e[0]].push_back(e[1]);
        vector<vector<vector<int> > > g{rg, bg};
        vector<vector<int> > res(n, {INF, INF});
        res[0] = {0, 0};
        dfs(g, 0, 0, res);
        dfs(g, 1, 0, res);
        vector<int> out(n);
        for (int i = 0; i < n; ++i) {
            out[i] = min(res[i][0], res[i][1]);
            if (out[i] == INF) out[i] = -1;
        }
        return out;
    }
};
```

![image.png](https://pic.leetcode-cn.com/e0250e54976780382c6fcc070142d22d27a45cbb9a9c129e1d0032bc5f503082-image.png)
