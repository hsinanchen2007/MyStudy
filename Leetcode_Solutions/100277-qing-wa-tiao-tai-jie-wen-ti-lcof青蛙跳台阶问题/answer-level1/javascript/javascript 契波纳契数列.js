```
var numWays = function(n) {
   let dp=new Array(n+1).fill(1);
   for(let i=2;i<=n;i++){
     dp[i]=(dp[i-1]+dp[i-2])%1000000007
   }
   return dp[n]
};
```
