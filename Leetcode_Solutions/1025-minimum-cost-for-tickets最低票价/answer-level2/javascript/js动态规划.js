### 解题思路
类似跳格子的题目：70. 爬楼梯
设某一天i的最小值为dp[i],i位置依据于与前一天的差值，如果小于7则可以从7的位置跳过来
如果大于7小于30则能从30天的位置跳过来
注意了，这里costs【0】并非最小值，并且如果减出来的结果为7，应当放在30格那一层
因为从8 - 1 = 7，买一张7的门票不能玩到第八天

### 代码

```javascript
/**
 * @param {number[]} days
 * @param {number[]} costs
 * @return {number}
 */
var mincostTickets = function(days, costs) {
    let dp = new Array(days.length).fill(Number.MAX_VALUE)
    //costs不按顺序
    let minCost = Math.min(Math.min(costs[0], costs[1]), costs[2])

    dp[0] = minCost

    for(let i = 1; i < days.length; i++) {
        dp[i] = Math.min(dp[i], dp[i - 1] + minCost)
        for(let j = 0; j < i; j++) {
            if((days[i] - days[j]) < 7) {
                dp[i] = Math.min(dp[i], (j - 1 < 0  ? 0: dp[j - 1]) + costs[1])
            }else if((days[i] - days[j]) < 30 && (days[i] - days[j]) >= 7){
                 dp[i] = Math.min(dp[i],  (j - 1 < 0  ? 0 : dp[j - 1]) + costs[2])
            }
        }
    }

    // console.log(dp)

    return dp[days.length - 1]
};
```