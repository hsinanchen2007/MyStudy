### 解题思路
1. 当前阶梯可能由上一个位置经过爬一层阶梯或者爬两层阶梯到达，因此取上一个位置的**最小值**加上到达该阶梯的花费即得到当前层的最小体力耗费

### 代码

```cpp
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.empty()) return 0;
        int n = cost.size();
        int dp[n];
        memset(dp, 0, sizeof(dp));
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i = 2; i < n; i++){
            dp[i] = min(dp[i-1], dp[i-2]) + cost[i];
        }
        //倒数第一个阶梯和倒数第二个阶梯都可以经过爬一步或者两步达到楼顶
        return min(dp[n-1], dp[n-2]);
    }
};
```