一开始的时候把动态规划的状态想成了0-没有完成过交易，1-完成过一次交易，2-完成了两次交易
后来发现这样状态还不够，索性改成0-5直接把，不买，买一次，卖一次，买两次，卖两次都列了出来
虽然这一步想的没有问题，可是下一步的初始化不会了，看了下其他人的题解，把之前忘掉的动态规划
基本规则重温了一边，遇到初始不可能有买两次这样的操作的时候，直接赋值一个不存在的数，一般是最大或者最小，
然后再进行状态转移方程推算就好了。
这一题的状态转移方程是求最大，所以我初始化把dp[0][3]赋值成MIN_VALUE，确保后面的状态不会被干扰，或者压根不会
走3这一个状态即可，这篇题解写在这里作为提醒自己而用。

有了这一题的经验，之后碰到其他类似的问题，买3次，4次，都可以套用了。


二维 7ms
```
class Solution {
    public int maxProfit(int[] prices) {

        int len = prices.length;
        if(len == 0)return 0;
        int[][] dp = new int[len][5];
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        dp[0][3] = Integer.MIN_VALUE;
        

        for(int i=1;i<len;i++){
            dp[i][0] = dp[i-1][0];
            dp[i][1] = Math.max(dp[i-1][1],dp[i-1][0]-prices[i]);
            dp[i][2] = Math.max(dp[i-1][2],dp[i-1][1]+prices[i]);
            dp[i][3] = Math.max(dp[i-1][3],dp[i-1][2]-prices[i]);
            dp[i][4] = Math.max(dp[i-1][4],dp[i-1][3]+prices[i]);
        }

        int max = 0;
        for(int i = 0; i<5; i++){
            if(dp[len-1][i]>max){
                max = dp[len-1][i];
            }
        }
        return max;
    }
}
```

降维 4ms
```
class Solution {
    public int maxProfit(int[] prices) {

        int len = prices.length;
        if(len == 0)return 0;
        int[][] dp = new int[len][5];
        dp[0] = 0;
        dp[1] = -prices[0];
        dp[3] = Integer.MIN_VALUE;
        

        for(int i=1;i<len;i++){
            dp[1] = Math.max(dp[i-1][1],dp[i-1][0]-prices[i]);
            dp[2] = Math.max(dp[i-1][2],dp[i-1][1]+prices[i]);
            dp[3] = Math.max(dp[i-1][3],dp[i-1][2]-prices[i]);
            dp[4] = Math.max(dp[i-1][4],dp[i-1][3]+prices[i]);
        }

        int max = 0;
        for(int i = 0; i<5; i++){
            if(dp[i]>max){
                max = dp[i];
            }
        }
        return max;
    }
}
```
