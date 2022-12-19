```
class Solution {
public:
    int dirs[8][2] = {
        {1, 2}, {2, 1}, {2, - 1}, {1, -2},
        {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};
    double knightProbability(int N, int K, int r, int c) {
        if (K == 0) return 1.0;
        vector<vector<double> > dp(N, vector<double>(N, 1));
        for (int k = 1; k <= K; ++k) {
            auto dp1 = dp;
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    dp1[i][j] = 0;
                    for (int l = 0; l < 8; ++l) {
                        int r = i + dirs[l][0];
                        int c = j + dirs[l][1];
                        if (r >= 0 && r < N && c >= 0 && c < N) {
                            dp1[i][j] += dp[r][c] / 8;
                        } 
                    }
                }
            }
            swap(dp1, dp);
        }
        return dp[r][c];
    }
};
```

![image.png](https://pic.leetcode-cn.com/dbc925aedd3598c28f047e74111639df6bc65f2632b81d39751167a1ae3066dd-image.png)
