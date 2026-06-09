# dp数组
dp[i] 含义是数字i的完全平方组合结果

# 状态转移
seed:平方种子

每次循环中实现回退，求（现在dp[i],回退seed^2后的dp[i]+1）的最小值

```
class Solution {
    public int numSquares(int n) {
        int[] dp = new int[n+1];
        Arrays.fill(dp,Integer.MAX_VALUE);
        dp[0] = 0;
        
        for(int i=0; i<=n; i++)
        {
          int seed = 1;
            while(((i-Math.pow(seed,2)))>=0){
                dp[i] = Math.min(dp[i],dp[i-(int)Math.pow(seed,2)]+1);
                seed++;
            }
        }
        
        return dp[n];
        
    }
}
```
