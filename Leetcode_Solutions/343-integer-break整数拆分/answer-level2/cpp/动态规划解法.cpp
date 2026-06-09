### 解题思路
方法比较简单，直接看代码即可。

### 代码

```cpp
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 1;
        for(int i = 3; i <= n; i++){
            for(int j = 1; j < i; j++){
                int t = max(max(dp[j]*dp[i-j], max(dp[j]*(i-j), j*dp[i-j])), j*(i-j));
                dp[i] = max(dp[i], t);
            }
        }
        return dp[n];
    }
};
```