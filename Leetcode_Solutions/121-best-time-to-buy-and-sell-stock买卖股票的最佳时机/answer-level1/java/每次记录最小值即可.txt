### 解题思路
记录最小值 然后拿当前数组值减即可

### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        //股票的最大利润 dp动态规划

        if (prices.length == 0) {
            return 0;
        }

        int minValue = prices[0];//最小买入值

        int maxSum   = 0;//最大的总和

        for (int i = 1; i < prices.length; i++) {
            if (prices[i] < minValue) {
                minValue = prices[i];
            } else {
                maxSum = Math.max(maxSum, (prices[i] - minValue));
            }
        }
        
        return maxSum;
    }
}
```