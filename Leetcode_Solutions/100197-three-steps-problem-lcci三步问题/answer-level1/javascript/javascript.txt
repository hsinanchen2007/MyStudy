```
var waysToStep = function(n) {
  const dp = new Array(n)
  let m = 1e9+7
  dp[0] = 1
  dp[1] = 1
  dp[2] = 2
  for (let i = 3; i <= n; i++) {
    dp[i] = (dp[i - 1] + dp[i - 2] + dp[i -3]) % m
  }
  return dp[n]
};
```
