```
class Solution {
public:
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    void dfs(vector<vector<int> >& g, int r, int c, int col) {
        int N = g.size();
        g[r][c] = col;
        for (int i = 0; i < 4; ++i) {
            int nr = r + dirs[i][0];
            int nc = c + dirs[i][1];
            if (nr >= 0 && nr < N && nc >= 0 && nc < N && g[nr][nc] == 0) {
                dfs(g, nr, nc, col);
            }
        }
    }
    int regionsBySlashes(vector<string>& grid) {
        int N = grid.size();
        vector<vector<int> > dg(3 * N, vector<int>(3 * N, 0));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                int r = 3 * i;
                int c = 3 * j;
                if (grid[i][j] == '/') {
                    dg[r][c + 2] = dg[r + 1][c + 1] = dg[r + 2][c] = 1;
                } else if (grid[i][j] == '\\') {
                    dg[r][c] = dg[r + 1][c + 1] = dg[r + 2][c + 2] = 1;
                }
            }
        }
        int col = 1;
        for (int i = 0; i < 3 * N; ++i) {
            for (int j = 0; j < 3 * N; ++j) {
                if (dg[i][j] == 0) {
                    dfs(dg, i, j, col);
                    ++col;
                }
            }
        }
        return col - 1;
    }
};
```

![image.png](https://pic.leetcode-cn.com/a92f5b273648f448e7510e3ee5656871d5742be1ff546424cc20129c790c7c16-image.png)
