### 解题思路
动态规划最优解的做法。
只需要遍历时，找到「当前的最小值」，
```
min = Math.min(min, prices[i])
```
那么在遍历的当前价格和最小值的差就是「最佳股票收益」。
```
max = Math.max(max, prices[i] - min)
```

### 代码

```javascript
/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
  if(prices.length <= 1) {
  return 0;
  }
  let min = prices[0]
  let max = 0
  for(let i= 1; i < prices.length; i++) {
    max = Math.max(max, prices[i] - min)
    min = Math.min(min, prices[i])
  }
  return max
};
```