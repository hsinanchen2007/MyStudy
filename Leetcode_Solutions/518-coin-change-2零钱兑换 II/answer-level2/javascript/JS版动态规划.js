js版动态规划，
注意的点有：
数组默认值为undefined，需要赋值为0才能正常进行累加 
当不传硬币数组，或传空数组时是不执行循环的，需要返回0，同样需要判断undefined处理
```
/**
 * @param {number} amount
 * @param {number[]} coins
 * @return {number}
 */
var change = function(amount, coins) {
    let dp = []
    dp[0] = 1
    for(let j = 0; j < coins.length; j++){
        for(let i = 1; i <= amount; i++){
            if(typeof dp[i] === 'undefined') dp[i] = 0 // 给每一项默认值赋为0,否则下面这一项会出错
            if(i >= coins[j]){
                dp[i] = dp[i] + dp[i - coins[j]]
            }
        }
    }
    if(typeof dp[amount] === 'undefined') return 0
    return dp[amount]
}
```
