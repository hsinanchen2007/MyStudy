### 解题思路
每一个台阶可以由下两个台阶或者下一个台阶得来
### 代码

```cpp
class Solution {
public:
    int climbStairs(int n) {
        int dp[100];
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3 ; i <= n ; ++i)
        dp[i] = dp[i - 1] + dp[i - 2];
        return dp[n];
    }
};
```