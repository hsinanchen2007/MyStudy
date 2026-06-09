```
代码块class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        if(prices.empty())
            return 0;
        //直接利用一个循环，找到最小的价钱作为买入价，并找到在此买入价下的最大利润
        int profit  = 0;
        int min = prices[0];
        for(int i = 1; i < prices.size(); i++)
        {
            if(min > prices[i])
                min = prices[i];
            else
                profit = max(profit, prices[i] - min);
        }
        return profit;
        
    }
};
```
