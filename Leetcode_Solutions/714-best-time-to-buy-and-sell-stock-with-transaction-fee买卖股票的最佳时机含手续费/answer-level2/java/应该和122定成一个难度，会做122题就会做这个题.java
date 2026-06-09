### 解题思路
![QQ截图20200403154343.png](https://pic.leetcode-cn.com/37776e00eaf6c9156e70f06c85febfd68f1aa24ffe4d421342f4df8e4fe39e4c-QQ%E6%88%AA%E5%9B%BE20200403154343.png)

没啥好讲的，把liweiwei大佬的题解粘在这里，我做股票题就是看他的题解启的蒙：
https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/solution/tan-xin-suan-fa-by-liweiwei1419-2/
### 代码

```java
class Solution {
    public int maxProfit(int[] prices, int fee) {
          int n=prices.length;
        if(n==0) return 0;
        int [][] dp=new int[n][2];
        dp[0][0]=0;
        dp[0][1]=-prices[0]-fee;
        for(int i=1;i<n;i++){
            dp[i][0]=Math.max(dp[i-1][0],dp[i-1][1]+prices[i]);
            dp[i][1]=Math.max(dp[i-1][1],dp[i-1][0]-prices[i]-fee);
        }
        return dp[n-1][0];

    }
}
```