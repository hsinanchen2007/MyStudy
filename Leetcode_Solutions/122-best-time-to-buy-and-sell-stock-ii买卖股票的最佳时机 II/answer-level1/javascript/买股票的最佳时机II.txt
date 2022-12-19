1、暴力破解
找出所有可能的交易组合，并找出他们利益的最大值
```javascript
/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    return calculate(prices,0);
};
const calculate = function (prices, s) {
    if (s >= prices.length) return 0;
    let max = 0;
    for (let start = s; start < prices.length; start++) {
        for (let i = start + 1; i < prices.length; i++) {
            if (prices[start] < prices[i]) {
                // 之后的交交易赚到的钱加上现在的交易赚到的钱
                let profit = calculate(prices, i + 1) + prices[i] - prices[start]
                max = Math.max(max,profit)
            }
        }
    }
    return max;
}
```
时间复杂度：O(n^n)，调用递归函数 n^n次。
空间复杂度：O(n)，递归的深度为 nn。
2. 贪心算法
每次交易，只要赚到钱就买入。
“贪心算法” 在每一步总是做出在当前看来最好的选择。这里求最大值，所以每次交易的时候，对比今天的股价和昨天的股价，贪心是决策是，如果大于0，则相加
```javascript
/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    let profit = 0;
    for(let i = 0; i < prices.length; i++) {
        let temp = prices[i+1] - prices[i];
        if(temp > 0) profit += temp;
    }
    return profit;
};
```
时间复杂度：O(n)，遍历一次。
空间复杂度：O(1)，需要常量的空间。