### 解题思路
简单列出之后模拟即可

### 代码

```cpp
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1,0);
        dp[0] = 0;
        dp[1] = 1;
        
        for(int i=2;i<=n;i++){
            for(int j=1;j<i;j++){
                dp[i] = max(dp[i],max(dp[i-j],i-j)*max(j,dp[j]));
            }
        }
        return dp[n];
    }
};
```