```javascript []
var maxProfit = function(prices) {
    let curMin = prices[0]
    let sum = 0
    for (let i=0;i<prices.length;i++) {
        if (prices[i] < curMin) {
            curMin = prices[i]
            continue;
        }
        sum = Math.max(prices[i] - curMin, sum)
    }
    return sum
};
```

之前想复杂了，其实这个问题可以抽象一点理解。

- 一个变量记录历史最大差值
- 一个变量保存当前最小值

遍历整个数组，有两种行为
- curValue < curMin. 当前值 小于 历史最小值，则更新历史最新值
- curValue > curMin. 则取 [当前值-历史最小值]与 历史最大差值 之间的较大值，更新 历史最大差值。

基本循环一遍就可以了