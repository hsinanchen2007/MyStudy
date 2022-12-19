### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        if(prices.length == 0)
            return 0;
        int[] dp = new int[prices.length];

        for(int i = 0; i < prices.length; i++){
            int min = prices[i];
            int max = 0;

            for(int j = i + 1; j < prices.length; j++){
                max = max > prices[j] ? max : prices[j];
            }

            if(max - min >= 0)
                dp[i] = max - min;
            else
                dp[i] = 0;
        }

        int max_value = dp[0];
        for(int i = 1; i < dp.length; i++){
            max_value = max_value > dp[i] ? max_value : dp[i];
        }
        return max_value;
    }
}
```