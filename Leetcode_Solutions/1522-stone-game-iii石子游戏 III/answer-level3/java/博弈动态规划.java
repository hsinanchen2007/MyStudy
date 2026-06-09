![image.png](https://pic.leetcode-cn.com/eeaaaeaa0256495943068b30da3253d4379405bdc4d8c954ad8dad9de5af5b55-image.png)

博弈动态规划
转移方程：dp[i] = max{-dp[i+1]+a[i], -dp[i+2]+a[i]+a[i+1], -dp[i+3]+a[i]+a[i+1]+a[i+2]}
dp[i]表示面临从第i到n-1堆时，己方得分与对方得分之差的最优值（谁面临谁是己方）
dp[i]可由dp[i+1],dp[i+2],dp[i+3]转移而来，也就是拿前1堆，前2堆，前3堆
dp[n]即面临从第n到n-1堆，没有这样的堆，所以有dp[n]=0
求解dp[0]
```
class Solution {
    public String stoneGameIII(int[] a) {
        int n = a.length;
        int dp[] = new int[n+1];
        
        dp[n] = 0;
        for(int i=n-1;i>=0;i--){
            dp[i] = -dp[i+1]+a[i];
            if(i+2<=n) dp[i] = Math.max(dp[i],-dp[i+2]+a[i]+a[i+1]);
            if(i+3<=n) dp[i] = Math.max(dp[i],-dp[i+3]+a[i]+a[i+1]+a[i+2]);
        }

        if(dp[0]>0) return "Alice";
        if(dp[0]<0) return "Bob";
        return "Tie";      
    }
    
}
```
