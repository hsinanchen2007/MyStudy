### 解题思路
动态规划，小心数组越界。

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        if(prices.size()<=1) return 0;      
        vector<int> diff(prices.size()-1);
        vector<int> dp(prices.size()-1);
        for(int i=0; i<prices.size()-1; ++i)
        {
            diff[i]=prices[i+1]-prices[i];
        }       
        dp[0]=max(0,diff[0]);
        int profit=dp[0];
        for(int i=1; i<diff.size(); ++i)
        {           
            dp[i]=max(0,dp[i-1]+diff[i]);
            profit=max(profit,dp[i]);
        }
        return profit;
    }
};    

```