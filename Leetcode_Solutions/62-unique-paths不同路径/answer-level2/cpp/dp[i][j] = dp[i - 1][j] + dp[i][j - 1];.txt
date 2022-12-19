### 解题思路
注意边界要初始化就好

### 代码

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[120][120] = {0};
        dp[1][1] = 1;
        dp[1][2] = 1;
        dp[2][1] = 1;
        for(int i = 2 ; i <= n ; ++i)
        dp[i][1] = 1;
        for(int i = 2 ; i <= m ; ++i)
        dp[1][i] = 1;
        for(int i = 2 ; i <= n ; ++i)
        {
            for(int j = 2 ; j <= m ; ++j)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[n][m];
    }
};
```