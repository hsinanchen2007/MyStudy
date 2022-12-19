令数组dp[i]为数字$i$分割的最大和。
对于数$i=j+(i-j)$总有

1. 分割成两个数$j,i-j$, $prt = j \times (i-j)$
2. 固定$i-j$不动，继续分割$j$, $prt = dp[j] \times (i-j)$
3. 固定$j$不动，继续分割$i-j$, $prt = j \times dp[i-j]$

则最终结果一定为三者中最大值

在遍历时要注意$(j,i-j), (i-j,j)$时同一种情况，则最多遍历到$i/2$。
```
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 0);
        dp[1] = 0;
        for(int i = 2; i <= n; ++i) {
            for(int j = 1; j <= i/2; ++j) {
                int cur = max(j*(i-j), max(dp[j] * (i-j), dp[i-j] * j));
                dp[i] = max(cur, dp[i]);
            }
        }

        return dp[n];
        
    }
};
```


