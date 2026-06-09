先看看前面几个数是怎样的，dp[1]=1,dp[2]=1,dp[3]=2.dp[4]=4,dp[5]=6,dp[8]=18.用动态规划来解答
```
 public int cuttingRope(int n){
        int[] dp = new int[n+1];
        dp[1]=1;
        for (int i = 2; i <= n; i++) {
            // j表示剪短的长度
           for(int j=1;j<=(i>>1);j++){
               // 需要比较 剪短的长度 与 这个长度继续剪的积的结果
               dp[i] = Math.max(dp[i],Math.max(j,dp[j])*Math.max(i-j,dp[i-j]));
           }
        }
        return dp[n];
    }
```
