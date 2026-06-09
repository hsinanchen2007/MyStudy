### 解题思路
递推

### 代码

```cpp
class Solution {
public:
    int dp[200];
    int mod=1e9+7;
    int numWays(int n) {
        if(n==0) return 1;
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++){
            dp[i]=(dp[i-2]+dp[i-1])%mod;
        }
        return dp[n];
    }
};
```