执行用时: 76 ms, 在所有 JavaScript 提交中击败了 97.17% 的用户

思路在于当日(i)价格下滑，则取昨日(i-1)卖出的价格差为此次获利。需要注意是在结束的时候需要卖出依旧持有的股票，计算价差获利。

```Javascript
var maxProfit = function (prices) {
    if (prices.length <= 0) {
        return 0;
    }
    let totalProfit = 0,
        minPrice = prices[0];
    // 若价格比前一日低，则以前一日卖出为获利，且在今日再次买入。
    for (let i = 1; i < prices.length; i++) {
        if (prices[i] < prices[i - 1]) {
            totalProfit += prices[i - 1] - minPrice;
            minPrice = prices[i];
        }
    }
    // 结束后卖出持有的股票（如有）
    totalProfit += prices[prices.length - 1] - minPrice;
    return totalProfit;
};
```