### 思路
到达第i层只可能有两种情况，i - 1 和 i - 2，因此可以得出dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2])。

### 代码

```cpp
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size();
        vector<int> dp(size + 1);
        for (int i = 2; i < size + 1; ++i) {
            dp[i] = min(dp[i - 2] + cost[i - 2], dp[i - 1] + cost[i - 1]);
        }
        return dp[size];
    }
};
```