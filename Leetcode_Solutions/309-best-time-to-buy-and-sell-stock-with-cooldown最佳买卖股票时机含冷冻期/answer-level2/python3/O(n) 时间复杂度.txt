```
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) <=1:
            return 0
        
        dp_keep_at_the_moment = 0
        dp_wait_at_the_moment = 0
        profit = [prices[i]-prices[i-1] for i in range(1,len(prices))]
        
        for x in profit:
            
            max_get_today = max([dp_keep_at_the_moment+x,dp_wait_at_the_moment]) 
            max_wait_today = max([dp_keep_at_the_moment,dp_wait_at_the_moment])
            
            dp_keep_at_the_moment = max_get_today
            dp_wait_at_the_moment = max_wait_today
        return max([dp_keep_at_the_moment,dp_wait_at_the_moment])
```
