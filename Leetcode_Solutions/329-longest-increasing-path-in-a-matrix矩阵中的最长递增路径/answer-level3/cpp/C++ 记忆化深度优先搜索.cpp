```C++ []
class Solution {
public:
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<int> > memo;
    int dfs(vector<vector<int> >& matrix, int r, int c, int R, int C) {
        if (memo[r][c] != 0) {
            return memo[r][c];
        }
        int t = 0;
        for (int i = 0; i < 4; ++i) {
            int nr = r + dirs[i][0];
            int nc = c + dirs[i][1];
            if (nr >= 0 && nr < R && nc >= 0 && nc < C && matrix[nr][nc] > matrix[r][c]) {
                t = max(t, dfs(matrix, nr, nc, R, C));
            }
        }
        memo[r][c] = 1 + t;
        return memo[r][c];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int R = matrix.size();
        int C = matrix[0].size();
        memo = vector<vector<int> >(R, vector<int>(C, 0));
        int res = 0;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                res = max(res, dfs(matrix, i, j, R, C));
            }
        }
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/aa84dc5d68e719fb95287c538105c6501917e7ff1c302e4ab23020ce67921b82-image.png)
