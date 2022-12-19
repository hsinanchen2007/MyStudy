### 解题思路
- 题目中所说的楼顶不在cost数组里面，需要在cost最后增加一个0，代表楼顶。
- 使用动态规划，dp[i]代表达到第i层所需要的最小花费，易知边界条件为dp[0] = cost[0]; dp[1] = cost[1];
- 到达第i层可以有两种方法，一种是从第i - 1层爬一级台阶到达，另一种是从第 i - 2 层爬两层到达，因此状态转移方程为：
- dp[i] = min(dp[i - 2], dp[i - 1]) + cost[i];
### 代码

```cpp
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);  //增加楼顶，体力花费为0
        int len = cost.size();
        int dp[len];
        for(int i = 0; i < len; i++){
            if(i <= 1)  dp[i] = cost[i];    //边界条件
            else{
                dp[i] = min(dp[i - 2], dp[i - 1]) + cost[i];    //状态转移方程
            }
        }
        return dp[len - 1];
    }
};
```