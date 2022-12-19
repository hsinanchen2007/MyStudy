### 解题思路
一次遍历法，只需要记录什么时候买和什么时候卖。当下一次比这一次低的时候买，当下一次比这一次高的时候且有股票的时候卖。

还有一种情况要单独考虑，当手里有股票且一直递增，直到最后一天时也要出售。

### 代码

```java
class Solution {
    public int maxProfit(int prices[]) {
        int min = -1;
        int result = 0;
        for (int i = 0; i < prices.length - 1; i++) {
            if (min == -1 && prices[i + 1] > prices[i]) {
                min = i;
            }
            if (min != -1) {
                if (prices[i + 1] < prices[i]) {
                    result += prices[i] - prices[min];
                    min = -1;
                } else if (i + 1 == prices.length - 1) {
                    result += prices[i + 1] - prices[min];
                }
            }
        }

        return result;
    }
}
```