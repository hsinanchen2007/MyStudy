### 解题思路

没有用难以理解的通用算法。而是分成两段做，这样就可以变成121题的延伸。

两段是指：从前向后扫，和从后往前扫。

### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        
        if(prices.length < 1)
        {
            return 0;
        }
        
        int[] dpForwardMaxProfit = new int[prices.length];
        
        int minPrice = Integer.MAX_VALUE;
        int maxForwardProfit = 0;
        for(int i=0;i<prices.length;i++)
        {
            minPrice = Math.min(minPrice, prices[i]);
            int profiti = prices[i] - minPrice;
            maxForwardProfit = Math.max(maxForwardProfit, profiti);
            
            dpForwardMaxProfit[i] = maxForwardProfit;
        }
        
        
        
        int maxPrice = Integer.MIN_VALUE;
        int maxBackwardProfit = 0;
        
        int[] dpBackwardMaxProfit = new int[prices.length];
        for(int i=prices.length-1;i>=0;i--)
        {
            maxPrice = Math.max(maxPrice, prices[i]);
            int profiti = maxPrice - prices[i];
            maxBackwardProfit = Math.max(maxBackwardProfit, profiti);
            dpBackwardMaxProfit[i] = maxBackwardProfit;
        }
        
        
        int result = 0;
        
        for(int i = 0;i<prices.length;i++ )
        {
            result = Math.max(dpBackwardMaxProfit[i]+ dpForwardMaxProfit[i], result);
        }
        
        return result;
    }
}
```