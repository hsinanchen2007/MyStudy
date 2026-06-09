### 解题思路

只要前一天的价格小于第二天，就在前一天买入，后一天卖出。把数组中所有差值 > 0 的加起来，就是最大利益。

### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        int maxProfit = 0;
        for (int i = 0; i < prices.length - 1; i++) {
            if (prices[i] < prices[i+1]) {
                maxProfit += prices[i + 1] - prices[i];
            }
        }
        return maxProfit;
    }
}
```