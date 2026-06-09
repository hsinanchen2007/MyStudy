### 解题思路

要到达第i步，有两种可能：要么由第i-1步跨一步获得，要么由第i-2步跨两步获得。
故dp[i]=dp[i-1]+dp[i-2];
需要注意：dp[0]=1;尽管这并没有实际的意义。
### 代码

```cpp
class Solution {
public:
    int dp[1001];
    int climbStairs(int n) {
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};
```