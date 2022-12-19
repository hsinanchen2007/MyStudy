
此方法是官方的一次遍历法的变相理解：
- 设定买入时机 in
- 后一天比当天价格高，且当前是未买状态，则买
- 后一天比当天价格低，且当前是已买状态，则卖
```java
class Solution {
    public int maxProfit(int[] prices) {
        int money = 0;
        int in = -1;
        for( int i = 0; i < prices.length-1; i++){
            int  temp = prices[i+1] -prices[i];
             if(temp>0 && in == -1){
                in = i;
            }else if(temp<0&&in!=-1) {
                money  = money + prices[i] - prices[in];
                in = -1;
            }
        }
        if(in!=-1){
            money = money + prices[prices.length-1] - prices[in];
        }
        return money;
    }
}
```

此思想进化之后，即是官方的`一次遍历`题解思想：后一天比前一天价格高，即累加利润值。

```java
class Solution {
    public int maxProfit(int[] prices) {
        int maxprofit = 0;
        for (int i = 1; i < prices.length; i++) {
            if (prices[i] > prices[i - 1])
                maxprofit += prices[i] - prices[i - 1];
        }
        return maxprofit;
    }
}
```