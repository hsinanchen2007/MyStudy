### 解题思路
按dp题思路做：

状态：楼梯数

dp数组含义：dp[i]表示i阶楼梯所需的方法数

方程：$dp[i] = dp[i-1] + dp[i-2],i>=2$

这不就是斐波那契数列吗？？

Base case: dp[0] = 0, dp[1] = 1, dp[2] = 2

双一百，done!
### 代码

```cpp
class Solution {
public:
    int climbStairs(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        if(n == 2) return 2;
        vector<int> dp(n + 1);
        //base case
        dp[0] = 0, dp[1] = 1, dp[2] = 2;
        for(int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
```