**状态**
`dp[i]`表示走到位置`i`所花费的最小体力，由于初始位置为0或1，因此`dp[0]`和`dp[1]`均为0

**状态转移方程**
`dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2])` 
走到索引`i`所花费的最小体力=min(到索引`i-1`所花的最小体力 + `i-1`处所花费的体力, 到索引`i-2`所花的最小体力 + `i-2`处所花费的体力)

**具体实现**
```
class Solution {
public:
  int minCostClimbingStairs(vector<int> &cost) {
    vector<int> dp(cost.size() + 1, 0);
    for (int i = 2; i <= cost.size(); ++i) {
      dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    }
    return dp.back();
  }
};
```
