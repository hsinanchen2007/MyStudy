### 解题思路
dp来做：

先分析：

状态：阶梯数

dp数组含义：dp[i]为到第i阶(第0阶是指没有阶梯，而不是有一阶!)的最小花费

方程：$dp[i] = min\{dp[i - 1] + costs[i - 2], dp[i - 2] + costs[i - 3]|i>=3\}$

这里要注意里面的costs[i-2]代表的是第i-2阶费用

base case: dp[0] = 0, dp[1] = 0, dp[2] = 0;

### 代码

```cpp
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int len = cost.size();
        vector<int> dp(len + 2);
        dp[0] = 0, dp[1] = 0, dp[2] = 0;
        for(int i = 3; i <= len + 1; i++) {
            dp[i] = min(dp[i - 1] + cost[i - 2], dp[i - 2] + cost[i - 3]);
        }
        return dp[len+1];
    }
};
```