### 解题思路
这题的关键买入卖出，只有先买入才能卖出，，所以就是求prices数组右边减左边的最大值

暴力法很简单，但是效率为n^2

我们可以定义两个变量l(买入)和r(卖出)，开始都赋值为peices数组的第一个元素，定义一个max变量，max=r-l

然后从下标为1开始遍历，如果当前遍历的数小于l，那么将l和r都赋值为当前遍历的数

如果当前遍历的数小于l但是大于r，那么r更新为当前遍历的数，同时更新max(将max和r-l取最大值)

最后返回max就可以了

### 代码

```javascript
/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
 const len = prices.length
  max = 0
  if  (len == 0) return max
  let l = 0
  let r = 0
  l = prices[0]
  r = prices[0]
  for (let i = 1; i < len; i++) {
    if (prices[i] < l) {
      l = prices[i]
      r = prices[i]
    } else {
      if (prices[i] > r)
        r = prices[i]
      max = Math.max(max,r-l)
    }
  }
  return max
}
```