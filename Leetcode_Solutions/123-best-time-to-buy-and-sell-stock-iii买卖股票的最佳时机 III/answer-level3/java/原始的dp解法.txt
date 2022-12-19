### 解题思路
这个是原始dp的样子，我就不优化了，各位可以看看
### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        if(prices.length<=1)
            return 0;
        int[][][] dp=new int[prices.length][3][2];// day ,the number of echange,hold
        dp[0][1][1]=-prices[0];
        dp[0][0][1]=Integer.MIN_VALUE;
        dp[0][0][0]=Integer.MIN_VALUE;
        for(int i=1;i<prices.length;i++){
            dp[i][1][1]=Math.max(dp[i-1][2][0]-prices[i],dp[i-1][1][1]);
            dp[i][1][0]=Math.max(dp[i-1][1][1]+prices[i],dp[i-1][1][0]);
            dp[i][0][1]=Math.max(dp[i-1][1][0]-prices[i],dp[i-1][0][1]);
            dp[i][0][0]=Math.max(dp[i-1][0][1]+prices[i],dp[i-1][0][0]);
        }
        return Math.max(dp[prices.length-1][0][0],dp[prices.length-1][1][0]);
    }
}
```