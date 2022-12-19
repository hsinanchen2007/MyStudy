### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size() == 0)return 0;
        //dp[i] = min(dp[i-1], dp[i-2]) + cost[i]
        int len = cost.size();
        //vector<int> dp(len, 0);
        //dp[0] = cost[0];
        //dp[1] = cost[1];
        int c0 = cost[0], c1 = cost[1];  //c0, c1相当于dp[0], dp[1]
        for(int i = 2; i < len; ++i)
        {
            //dp[i] = min(dp[i-2], dp[i-1]) + cost[i];
            int cur = min(c0 , c1) + cost[i];
            c0 = c1;
            c1 = cur;
        }
        //return min(dp[len-1], dp[len-2]);
        return min(c0, c1);
    }
};
```