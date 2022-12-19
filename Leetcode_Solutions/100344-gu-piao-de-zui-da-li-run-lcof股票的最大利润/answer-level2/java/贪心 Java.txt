### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        if (null == prices || 1 >= prices.length)
            return 0;

        int min = prices[0];
        int maxDiff = 0;
        
        for (int n: prices) {
            if (n < min)
                min = n;
            if (n-min > maxDiff)
                maxDiff = n-min;
        }
        return maxDiff;
    }
}
```