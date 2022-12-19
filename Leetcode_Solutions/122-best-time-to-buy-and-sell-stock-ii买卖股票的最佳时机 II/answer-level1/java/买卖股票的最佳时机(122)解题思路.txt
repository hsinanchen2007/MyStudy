### 解题思路
对于 [a, b, c, d]，如果有 a <= b <= c <= d ，那么最大收益为 d - a。而 d - a = (d - c) + (c - b) + (b - a) ，因此当访问到一个 prices[i] 且 prices[i] - prices[i-1] > 0，那么就把 prices[i] - prices[i-1] 添加加到收益中，从而在局部最优的情况下也保证全局最优。

### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        int profit = 0;
        for(int i = 0 ; i < prices.length - 1 ; i++)
        {
           if(prices[i+1]>prices[i])
           {
               profit += (prices[i+1]-prices[i]);
           }
        }
        return profit;
    }
}
```