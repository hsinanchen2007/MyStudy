
贪心算法，每天为一步，只取正收益， 负收益不要（设为0）。而每一天的收益 = 今天股价 - 昨天的股价。
（看了不少人的题解都需要判断数组长度等于0、1的情况，其实直接从1开始循环即可，不用判断）

```js
var maxProfit = function(prices) {
    let sum = 0
    for(let i=1; i<prices.length; i++) {
        sum += Math.max(prices[i] - prices[i-1], 0)
    }
    return sum
};
```
