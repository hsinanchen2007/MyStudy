### 解题思路
递推

### 代码

```cpp
class Solution {
public:
    int dp[200];
    int mod=1e9+7;
    int fib(int n) {
        dp[0]=0;
        dp[1]=1; dp[2]=1;
        if(n<=2) return dp[n];
        for(int i=3;i<=n;i++){
            dp[i]=((dp[i-1]+dp[i-2])%mod);
        }
        return dp[n];
    }
};
```