### 解题思路
只能买入一次，卖出一次。并且买入在卖出之前。
数组中索引为    0,1,2...buyIndex...sellIndex...prices.length - 1
最大利润为      prices[sellIndex] - prices[buyIndex]
最大利润也可以表示为   sellIndex 与 byIndex 之间的差值之和
(prices[sellIndex] - prices[sellIndex - 1]) + (prices[sellIndex - 1] - prices[sellIndex - 2]) + ... + (prices[buyIndex + 1] - prices[buyIndex])
最后就转化为最大连续子序和问题

### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        if (prices == null || prices.length <= 1)
            return 0;

        for (int i = prices.length - 1; i > 0; i--){
            prices[i] = prices[i] - prices[i - 1];
        }

        int sum = prices[1];
        int maxSum = prices[1];
        for (int i = 2; i < prices.length; i++){
            if (sum <= 0)
                sum = prices[i];
            else
                sum += prices[i];
            if (sum > maxSum)
                maxSum = sum;
        }

        return maxSum > 0 ? maxSum :0;
    }
}
```