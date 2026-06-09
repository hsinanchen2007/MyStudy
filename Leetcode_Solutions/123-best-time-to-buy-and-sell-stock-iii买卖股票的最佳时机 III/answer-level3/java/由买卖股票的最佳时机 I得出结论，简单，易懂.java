### 解题思路
从买卖股票的最佳时机 I中，得出解得一次买卖股票的最大利润，所以这道题可以直接从头遍历求出前 i 个最大并且从第 i+1 个到最后一个中最大利润，得出两个的最大和。

### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        if(prices.length == 1) 
            return 0;
        if(prices.length == 2)
            return prices[1] - prices[0] > 0 ? prices[1] - prices[0] : 0;
        int res = 0;
        for(int i = 1;i<prices.length;i++) {
            int front = maxByRange(prices, 0, i);
            int behind = maxByRange(prices, i+1, prices.length-1);
            if(front + behind > res) 
                res = front + behind;
        }
        return res;
    }

    public int maxByRange(int[] prices,int i, int j) {
        int min_prices = Integer.MAX_VALUE;
        int max_profit = 0;
        for (int k = i;k<=j;k++) {
            if(prices[k] < min_prices) {
                min_prices = prices[k];
            }else if(prices[k] - min_prices > max_profit){
                max_profit = prices[k] - min_prices;
            }
        }
        return max_profit;
    }
}
```