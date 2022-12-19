### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} n
 * @return {number[]}
 */
var twoSum = function(n) {
    let num = n * 6;
    dp = [];
    for(let i = 0; i <= n; i ++){
        dp.push(new Array(num+1).fill(0))
    }
    for(let i = 1; i <= 6; i++){
        dp[1][i] = 1;
    }
    for(let i = 2; i <= n; i++){
        for(let j = i; j <= i * 6; j++){
            if(j > 6){
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j - 2] + dp[i - 1][j - 3] + dp[i - 1][j - 4] + dp[i - 1][j - 5] + dp[i - 1][j - 6]
            } else {
                dp[i][j] = ((j - 1) > 0 ? dp[i - 1][j - 1] : 0) + ((j - 2) > 0 ? dp[i - 1][j - 2] : 0) + ((j - 3) > 0 ? dp[i - 1][j - 3] : 0) + ((j - 4) > 0 ? dp[i - 1][j - 4] : 0) + ((j - 5) > 0 ? dp[i - 1][j - 5] : 0) + ((j - 6) > 0 ? dp[i - 1][j - 6] : 0)
            }
        }
    }
    let sum = dp[n].reduce((old, curr) => {
        return old + curr
    })
    let ans = dp[n].map(value => {
        return value / sum;
    })
    return ans.slice(n)
};
```