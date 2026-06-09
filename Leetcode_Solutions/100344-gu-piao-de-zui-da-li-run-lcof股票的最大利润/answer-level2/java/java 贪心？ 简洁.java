### 解题思路
/**
 * 一种贪心的思想？
 * 遇到小的买入点就‘买’（left）
 * 遇到大的就卖试一试
 */

### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        int left = 0, right = 0;
        int max = 0;
        for (; right < prices.length; right++) {
            if (prices[right] > prices[left]) {
                max = Math.max(prices[right] - prices[left], max);
            } else {
                left = right;
            }
        }
        return max;
    }
}

```