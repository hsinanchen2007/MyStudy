### 解题思路
状态：楼梯数

dp数组含义: dp[i]表示i阶所对应的方法数

方程：$dp[i] = dp[i-1] + dp[i-2] + dp[i-3],i>3$

base case：$dp[0] = 0,dp[1] = 1, dp[2] = 2, dp[3] = 4$

我感觉吧，这题并不是难在写出动态规划写法，而是对于这么大的一个数的处理，须知在每一次处理时便取余和直接对结果取余的答案一致。

### 代码

```cpp
class Solution {
public:
    int waysToStep(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;
        vector<long long> dp(n + 1);
        dp[0] = 0, dp[1] = 1, dp[2] = 2, dp[3] = 4;
        for(int i = 4; i <= n; i++) {
            dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3])%(1000000007);
        }
        return dp[n];
    }
};
```