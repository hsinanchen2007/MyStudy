```
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int length=cost.size();
        int dp[length+1]={0};
        dp[0]=0;
        dp[1]=0;
        for(int k=2;k<=cost.size();k++){
            dp[k]=min(dp[k-1]+cost[k-1],dp[k-2]+cost[k-2]);
        }
        return dp[length];
    }
};
```
