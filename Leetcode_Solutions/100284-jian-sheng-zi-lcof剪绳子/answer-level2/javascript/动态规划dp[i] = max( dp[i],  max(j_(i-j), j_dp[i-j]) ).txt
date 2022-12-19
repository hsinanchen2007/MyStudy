### 解题思路
动态规划

### 代码

```javascript
/**
 * @param {number} n
 * @return {number}
 */
var cuttingRope = function(n) {
    // var res=1;
    var dp=new Array(n+1).fill(0)
    // dp[1]=[1];
    dp[2]=[1];
    for(var i=3;i<=n;i++){
        for(var j=2;j<=i-1;j++){
            dp[i]=Math.max(dp[i], Math.max(j*dp[i-j],j*(i-j)));
        }
        console.log(dp[i]);
    }
    return dp[n];
};




```