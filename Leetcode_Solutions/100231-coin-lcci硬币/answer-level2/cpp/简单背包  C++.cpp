### 解题思路
简单背包，动态规划解决
![码农黑板报.png](https://pic.leetcode-cn.com/287299e9f22c81d5bd92396e9cc78e440e831357600172130655de1b1defdba9-%E7%A0%81%E5%86%9C%E9%BB%91%E6%9D%BF%E6%8A%A5.png)


### 代码

```cpp
class Solution {
public:
    int waysToChange(int n) {
        int coins[] = {1,5,10,25};
        int dp[4][n+1];
        for (int i = 0; i < 4; i++) {
            dp[i][0] = 1;
        }
        for (int j = 0; j <= n; j++) {
            dp[0][j] = 1;
        }
        for (int i = 1; i < 4; i++) {
            for (int j = 0; j <= n; j++) {
                if (j >= coins[i]) {
                    dp[i][j] = (dp[i-1][j] + dp[i][j-coins[i]])%1000000007;
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[3][n];
    }
};
```