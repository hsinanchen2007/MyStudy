### 解题思路

### 代码

```cpp
class Solution 
{
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        int n=cost.size();
        vector<int> dp(n,0);  //dp[i]为到i级的最少花费

        for(int i=0;i<n;i++)
        {
            if(i==0 || i==1) dp[i]=cost[i];
            else dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
        }

        return min(dp[n-1],dp[n-2]);
    }
};
```