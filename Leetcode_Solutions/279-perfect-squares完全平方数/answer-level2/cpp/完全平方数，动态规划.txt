### 解题思路
记dp[i]为和为i的完全平方数的个数，那么对于j，dp[i+j*j] 为dp[i+j*j]与dp[i]+1(即和为i的个数再加上j，即1)的较小值

### 代码

```cpp
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX);
        dp[0] = 0;
        for(int i = 0;i <= n;++i ){
            for(int j = 1;i + j*j <= n;++j){
                dp[i + j*j] = min(dp[i+j*j],dp[i]+1);
            }
        }
        return dp.back();
    }
};
```