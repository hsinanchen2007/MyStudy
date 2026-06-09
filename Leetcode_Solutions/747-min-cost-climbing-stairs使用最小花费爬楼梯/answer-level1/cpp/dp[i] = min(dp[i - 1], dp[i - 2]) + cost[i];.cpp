### 解题思路
注意点就是最后要单独再判断一下倒数两个台阶

### 代码

```cpp
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
    int dp[1010] = {0};
    dp[0] = cost[0];
    dp[1] = cost[1];
    for(int i = 2 ; i < cost.size() ; ++i)
        dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
    for(int i = cost.size() ; i <= cost.size() + 1 ; ++i)
        dp[i] = min(dp[i - 1], dp[i - 2]) ;
    return min(dp[cost.size()], dp[cost.size() + 1]);
    }
};
```