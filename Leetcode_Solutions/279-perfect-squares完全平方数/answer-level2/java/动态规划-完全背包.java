01背包问题，与零钱兑换属于同一种题目，代码稍微调整一下便是本题的答案
[零钱兑换](https://leetcode-cn.com/problems/coin-change)
```
class Solution {
    public int numSquares(int n) {
        int coins=(int)Math.sqrt(n)+1;
        int[] dp=new int[n+1];
        for(int i=1;i<=n;i++){
            int ans=n+1;
            for(int coin=1;coin<=coins;coin++){
                if((i-coin*coin)>=0) ans=Math.min(ans,dp[i-coin*coin]+1);
                else break;
            }
            dp[i]=ans;
        }
        return dp[n]>n?-1:dp[n];
    }
}
```
