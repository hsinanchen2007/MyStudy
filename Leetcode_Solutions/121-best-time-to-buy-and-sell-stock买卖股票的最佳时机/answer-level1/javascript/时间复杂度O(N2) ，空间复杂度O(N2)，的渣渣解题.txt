### 解题思路
此处撰写解题思路
使用双for 拿prices[i] 分别和prices[j] 比较得到最大的差值
### 代码

```javascript
/**
 * @param {number[]} prices
 * @return {number}
 */

const maxProfit = function(prices) {
  let max = 0;
  for (let i = 0; i < prices.length; i++) {
    for (let j = i; j < prices.length; j++) {
      max = Math.max(prices[j] - prices[i], max);
    }
  }
  return max;
};
```