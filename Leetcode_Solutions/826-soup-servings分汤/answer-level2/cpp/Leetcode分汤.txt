    和题解1的思路类似，但是方向相反，我们从dp[N][N]反推概率P。代码如下：
```
public:
    double soupServings(int N) {
        if (N > 6000)
            return 1.0;
        if (N == 0)
            return 0.5;
        N = int(ceil(N / 25.0));
        int alloc[4][2] = {{4, 0},
                           {3, 1},
                           {2, 2},
                           {1, 3}};
        double dp[N + 1][N + 1];
        memset(dp, 0, sizeof(dp));
        dp[N][N] = 1.0;

        double p = 0.0;
        for (int i = N; i > 0; i--) {
            for (int j = N; j > 0; j--) {
                if (dp[i][j] > 0) {
                    for (int k = 0; k < 4; k++) {
                        int m = alloc[k][0];
                        int n = alloc[k][1];
                        if (i <= m && j <= n) {
                            p += dp[i][j] * 0.125;
                        } else if (i <= m && j > n) {
                            p += dp[i][j] * 0.25;
                        } else if (i > m && j > n) {
                            dp[i - m][j - n] += dp[i][j] * 0.25;
                        }
                    }
                }
            }
        }
        return p;
    }
```
![image.png](https://pic.leetcode-cn.com/acc9f18a9fec8aeaccfc451c5361b3877d187165fafebd2f63e51e297429daf4-image.png)
