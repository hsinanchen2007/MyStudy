### 解题思路
对于任意一个较低的价格，我们可以一直等到它价值递增结束的时候再卖。

### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        int maxProfit = 0;

        // 可以一直等到递增完再卖
        for (int i = 1; i < prices.length; i++){
            maxProfit += Math.max(0, prices[i] - prices[i-1]);
        }
        return maxProfit;
    }
}
```