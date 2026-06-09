### 解题思路
动态规划
这道题挺简单的，就是一个个拆。
比如说 求10，就是拆成
1 9
2 8
3 7
4 6
5 5
...
注意，如果拆了之后的最大值，还不如本身，那就不拆，比如说2.

### 代码

```javascript
/**
 * @param {number} n
 * @return {number}
 */
var integerBreak = function(n) {
    let dp = [0, 1, 1];
    for(let i = 1; i <= n; i++){
        max = 1
        for(let j = 1; j < i; j++){
            max = Math.max(max, Math.max(dp[j], j) * Math.max(dp[i-j], i-j));   
        }
        dp[i] = max;
    }
    return dp[n];
};
```