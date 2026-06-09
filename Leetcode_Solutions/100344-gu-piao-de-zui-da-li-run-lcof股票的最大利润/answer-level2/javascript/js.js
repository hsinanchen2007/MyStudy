### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function (prices) {
    // 枚举在那一天卖，
    // 求前i天最小值
    // 使用minv表示前i-1天的最小值
    let res = 0;
    let minv = prices[0];
    for (let i = 0; i < prices.length; i++) {
        // 假设在第i天卖，获得的利润就是减去前面的最小值，也就是在最小值那天买入
        res = Math.max(res, prices[i] - minv);
        // 更新最小值
        minv = Math.min(minv, prices[i]);
    }
    return res;
};
```