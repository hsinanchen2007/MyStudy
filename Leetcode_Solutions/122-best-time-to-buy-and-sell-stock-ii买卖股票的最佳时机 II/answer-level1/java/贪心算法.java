只看今明两天，只要明天比今天贵，那今天买明天卖就赚到，否则不做操作，以此类推即可。


```java []
class Solution {
    public int maxProfit(int[] prices) {
        int maxProfit = 0;
        for(int i =1 ; i <prices.length;i++){
            if(prices[i]>prices[i-1]){
                maxProfit += (prices[i]-prices[i-1]);
            }
        }
        return maxProfit;        
    }
}
```


