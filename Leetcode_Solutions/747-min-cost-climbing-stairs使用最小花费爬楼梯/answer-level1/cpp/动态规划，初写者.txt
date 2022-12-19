### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:    //动态规划，写这种动态规划，还是要在纸上算一算，否则靠脑子空想是不能得到结果的，还有一点就是写这种题目就是要大胆找感觉，不是所有题目我们都会做，我要做的就是汲取前人的知识，在大胆想象。动手操作。
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size()==0) return 0;
        if(cost.size()==1) return cost[0];
        if(cost.size()==2) return cost[0]>cost[1]?cost[1]:cost[0];
        int dp[cost.size()];
        memset(dp,0,sizeof(dp));
        dp[0]=cost[0];
        dp[1]=cost[1];    //状态转移方程 ：dp[i]=max{dp[i-1]+cost[i],dp[i-2]+cost[i]};
        for(int i=2;i<cost.size();i++){
            dp[i]=min(dp[i-1],dp[i-2])+cost[i];
        }
        return dp[cost.size()-2]>dp[cost.size()-1]?dp[cost.size()-1]:dp[cost.size()-2];
    }
};
```