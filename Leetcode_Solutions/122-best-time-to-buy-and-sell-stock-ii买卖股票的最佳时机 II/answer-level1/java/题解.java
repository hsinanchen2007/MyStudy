### 解题思路
一开始用的递归搜索，考虑了所有情况但是超时了，所以用了贪心，直接将所有的正数差加起来就是最大的利润
### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        int profit = 0;
        for (int i = 1; i < prices.length; i++) {
            profit += Math.max(prices[i] - prices[i - 1], 0);
        }
        return profit;
    }
}
```