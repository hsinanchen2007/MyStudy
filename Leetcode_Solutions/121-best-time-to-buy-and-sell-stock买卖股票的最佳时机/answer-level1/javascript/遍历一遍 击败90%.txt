### 解题思路
遍历一遍 O（n）

### 代码

```javascript
/**
 * @param {number[]} prices
 * @return {number}
 */
// 暴力法
// var maxProfit = function(prices) {
//     let max = 0
//     for(let i in prices) {
//         if(i - 0 == prices.length - 1) return max
//         for(let j = i - 0 + 1; j < prices.length; j++){
//             max = Math.max(max, prices[j] - prices[i])
//         }
//     }
//     return max
// };
// 遍历一遍
var maxProfit = function(prices) {
    let min = prices[0]
    let max = 0
    prices.forEach((ele, index) => {
        if(ele - min > max && index > 0) max = ele - min
        if(min > ele) min = ele 
    })
    return max
};
```