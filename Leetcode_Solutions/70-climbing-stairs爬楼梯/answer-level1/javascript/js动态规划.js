```
/**
 * @param {number} n
 * @return {number}
 */
var climbStairs = function(n) {
    let memo = new Array(n+1).fill(-1)
    memo[0] = 1
    memo[1] = 1
    for(let i = 2; i <= n; i++) {
        memo[i] = memo[i-1] + memo[i - 2]
    }
    return memo[n]
};
```
