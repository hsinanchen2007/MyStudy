### 解题思路
dp[i][j]是前i个骰子，剩余重量j的搭配方式
当投完i个骰子，前一个状态就是[i - 1][j],遍历k，取这个物品为j - k => dp[i - 1][j - k]
将所有能组合的情况相加，即dp[i][j] += dp[i - 1][j - k]

### 代码

```javascript
/**
 * @param {number} d
 * @param {number} f
 * @param {number} target
 * @return {number}
 */
var numRollsToTarget = function(d, f, target) {
    // 多重背包
     let dp = []

     for(let i = 0; i < d; i++) {
         dp[i] = []
         for(let j = 0; j <= target; j++) {
             dp[i][j] = 0
         }
     }

     for (let i = 1; i <= Math.min(f, target); i++) {
            dp[0][i] = 1;
        }


     for(let i = 1; i < d; i++) {
         for(let j = 1; j <= target; j++) {
             for(let k = 1; k <= f && k <= j; k++) {
                 dp[i][j] = (dp[i][j] +  dp[i - 1][j - k])%1000000007
             }
         }
     }

    //  console.log(dp)

     return dp[d - 1][target]


};
```