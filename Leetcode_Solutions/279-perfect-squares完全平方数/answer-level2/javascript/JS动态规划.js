
```
var numSquares = function(n) {
    let dp=new Array(n+1).fill(0)
    for(let i=0;i<=n;i++){
        dp[i]=i;
        for(let j=0;i-j*j>0;j++){
            dp[i]=Math.min(dp[i],dp[i-j*j]+1)
        }
    }
    return dp[n]
};

```
解释一下转移方程
我们先假设dp[i]是由i个1组成的，这是最坏的情况.即dp[i]=i;
再假设有一个比i小的数k，dp[k]=k;正常情况下dp[i]=dp[k]+i-k。
但是如果i和k之间有一个j满足i-j*j=k，那我们是不是可以得出dp[i]=dp[k]+1呢；
将k=i-j*j代入,得到dp[i]=dp[i-j*j]+1；