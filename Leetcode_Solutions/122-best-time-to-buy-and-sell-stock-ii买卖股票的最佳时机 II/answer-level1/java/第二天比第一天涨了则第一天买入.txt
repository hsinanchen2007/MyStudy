### 解题思路
第二天比第一天涨了则第一天买入

### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        int maxProfit = 0;
        if (prices.length == 1 || prices.length == 0) {
            return 0;
        }
        int index = 1;
        while (index < prices.length) {
            // 1、第二天比第一天涨了则第一天买入
            if (prices[index - 1] < prices[index]) {
                maxProfit = maxProfit + (prices[index] - prices[index - 1]);
            }
            index ++;
        }
        return maxProfit;
    }
}
```