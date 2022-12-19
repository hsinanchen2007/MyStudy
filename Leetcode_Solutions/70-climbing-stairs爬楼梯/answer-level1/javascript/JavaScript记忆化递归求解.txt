### 解题思路
小于3的时候直接返回n
否则在dp[n]为undefined的时候去递归，已经算过的就不要递归了，防止溢出，速度比动态规划快些
执行用时 :
56 ms
, 在所有 JavaScript 提交中击败了
91.75%
的用户

### 代码

```javascript
/**
 * @param {number} n
 * @return {number}
 */
let dp = [0, 1, 2]
var climbStairs = function(n) {
    if (n < 3) return n
    if (dp[n] === undefined) dp[n] = climbStairs(n-1) + climbStairs(n-2)
    return dp[n]
};
```