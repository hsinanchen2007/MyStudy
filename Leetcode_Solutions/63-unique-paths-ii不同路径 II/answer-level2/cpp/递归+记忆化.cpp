比较好理解，但是肯定比dp慢。。。就是写起来简单
```
using pii = pair<int, int>;
class Solution {
private:
    map<pii, int> tmp;
    int m, n;
public:
    int dfs(vector<vector<int>> &g, int r, int c) {
        int res = 0;
        auto f = tmp.find({r, c});
        if (f != tmp.end()) return f->second;
        if (r == m - 1 && c == n - 1 && !g[r][c]) return 1;
        if (!g[r][c]) {
            g[r][c] = 1;
            if (r + 1 < m) res += dfs(g, r + 1, c);
            if (c + 1 < n) res += dfs(g, r, c + 1);
            g[r][c] = 0;
        }
        tmp[{r, c}] = res;
        return res;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        m = g.size(), n = g[0].size();
        return dfs(g, 0, 0);
    }
};
```
