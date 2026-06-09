### 解题思路

找到最低交易时间和后续最高交易时间就可以了

### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        if (prices.length <=1) {
            return 0;
        }
        int min = prices[0];
        int max = 0;
        for (int price : prices) {
            if (price - min < 0) {
                min = price;
            }
            if (price - min > max) {
                max = price - min;
            }
        }
        return max;
    }
}
```