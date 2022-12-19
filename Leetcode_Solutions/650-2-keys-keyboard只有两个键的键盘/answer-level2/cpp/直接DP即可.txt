### 解题思路
分析，当元素为素数时，只能1个1个往上加，即 n / 1  = 次数；
当元素不是为素数时，此时可以进行分解 ，例如 6 = 2 * 3, 那么dp[6] = min (dp[3] + 2, dp[2] + 3); 
以此类推，求解得答案。

### 代码

```cpp
class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n + 1, 0);
        for (int i = 2; i < n + 1; i++) {
            int minCount = INT_MAX;
            for (int j = 1; j < i; j++) {
                if (i % j == 0) {
                    minCount = min(dp[j] + i / j, minCount);
                }
            }
            dp[i] = minCount;
        }
        return dp[n];
    }
};
```