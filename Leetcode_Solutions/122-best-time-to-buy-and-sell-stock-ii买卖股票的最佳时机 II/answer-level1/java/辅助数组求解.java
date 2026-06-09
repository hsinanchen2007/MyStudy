首先题目中说到
>给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
这句话暗示我们每一天的利润和第i个元素相关，于是我们创建一个dp数组
如果要计算每天每天的利润 那么 
```
dp[i] = prices[i] -prices[i-1]
```
然后加上条件 i  >i+1 ,然后依次求出 dp数组的元素，然后求和即可

```java
class Solution {
    public int maxProfit(int[] prices) {
              if (prices==null) {
            return 0;
        }
        if (prices.length==0) {
            return 0;
        }
        int[]dp = new int[prices.length];
        dp[0] = 0;
        int max = dp[0];
        for (int i = 1; i < prices.length; i++) {
            if (prices[i]>prices[i-1]) {
                dp[i] = prices[i]-prices[i-1];

            }
        }
        int sum = 0;
        for (int i = 0; i < dp.length; i++) {
            sum+=dp[i];
        }
        return sum;
    }
    
}
```
