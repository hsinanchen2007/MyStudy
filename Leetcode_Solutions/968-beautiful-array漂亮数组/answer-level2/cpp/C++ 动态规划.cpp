参考官方题解，改写成了动态规划写法
```
class Solution {
public:
    vector<int> beautifulArray(int N) {
        vector<vector<int> > dp(N + 2);
        dp[1] = {1};
        dp[2] = {1, 2};
        for (int i = 3; i <= N; ++i) {
            dp[i].resize(i);
            for (int j = 0; j < (i + 1) / 2; ++j) {
                dp[i][j] = 2 * dp[(i + 1) / 2][j] - 1;
            }
            for (int j = 0; j < i / 2; ++j) {
                dp[i][j + (i + 1) / 2] = 2 * dp[i / 2][j];
            }
        }
        return dp[N];
    }
};
```
![image.png](https://pic.leetcode-cn.com/b7854e810b841ad9f343b17a7712de712766ac99a59ce982947ab59cc111d5ad-image.png)
