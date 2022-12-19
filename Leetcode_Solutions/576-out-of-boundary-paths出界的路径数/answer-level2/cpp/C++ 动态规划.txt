```
class Solution {
public:
    const long M = 1e9 + 7;
    int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int findPaths(int m, int n, int N, int p, int q) {
        if (N == 0) return 0;
        vector<vector<long> > dp(m, vector<long>(n, 0));
        for (int i = 0; i < m; ++i) {
            ++dp[i][0];
            ++dp[i][n - 1];
        }
        for (int i = 0; i < n; ++i) {
            ++dp[0][i];
            ++dp[m - 1][i];
        }
        vector<vector<long> > f = dp;
        for (int k = 2; k <= N; ++k) {
            auto dp1 = dp;
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    dp1[i][j] = 0;
                    for (int l = 0; l < 4; ++l) {
                        int r = i + dirs[l][0];
                        int c = j + dirs[l][1];
                        if (r >= 0 && r < m && c >= 0 && c < n) {
                            dp1[i][j] += dp[r][c];
                            dp1[i][j] %= M;
                        }
                    }
                    f[i][j] += dp1[i][j];
                    f[i][j] %= M;
                }
            }
            swap(dp1, dp);
        }
        return f[p][q];
    }
};
```

![image.png](https://pic.leetcode-cn.com/61e05f24a2663ef9b74308b5ca9f8b57ea5c45b9c06736f848745b4760ca5458-image.png)
