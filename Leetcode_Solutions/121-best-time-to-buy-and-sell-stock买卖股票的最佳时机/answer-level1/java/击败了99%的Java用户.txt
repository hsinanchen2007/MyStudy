```
public int maxProfit(int[] prices) {
        if(prices == null || prices.length == 0){
            return 0;
        }
        int minPrice = prices[0];
        int maxProfit = 0;
        for(int i = 1; i < prices.length; i++){
            maxProfit = maxProfit > (prices[i] - minPrice) ? maxProfit : (prices[i] - minPrice);
            minPrice = minPrice < prices[i] ? minPrice : prices[i];
        }
        return maxProfit;
    }
```
