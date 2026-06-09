# 思路
遍历数组时，记录当前所遍历过的最小值。
若当前遍历值 < 所遍历过的最小值，则更新最小值；
否则，用当前遍历值 - 所遍历过的最小值。

# 代码
```java
class Solution {
    public int maxProfit(int[] prices) {
        int min_price = Integer.MAX_VALUE, res = 0;
        for (int price : prices) {
            if (price < min_price)
                min_price = price;
            else
                res = Math.max(res, price - min_price);
        }
        return res;
    }
}
```
