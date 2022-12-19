### 解题思路

### 代码

```cpp
class Solution {
public:
    int numWays(int n) {
        int dp[n + 1];
        dp[0] = 1;
        if(n == 0)
        return dp[0];
        dp[1] = 1;
        if(n == 1)
        return dp[1];
        dp[2] = 2;
        if(n == 2)
        return dp[2];
        for(int i = 3 ; i <= n ; ++i)
        {
            dp[i] = (dp[i - 1] % 1000000007 + dp[i - 2] % 1000000007) % 1000000007;
        }
        return dp[n];
    }
};
```