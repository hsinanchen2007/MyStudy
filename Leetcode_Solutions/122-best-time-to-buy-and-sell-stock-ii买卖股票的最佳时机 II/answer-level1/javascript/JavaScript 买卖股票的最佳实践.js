### 解题思路

通过2个for循环找买入时机和卖出时机。
当天价格比第二天低是，当天为买入时机。
当天价格比第二天高时，当天为卖出时间。

### 代码

```javascript
/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
  const length = prices.length
  let earn = 0
  for (let i = 0; i < length - 1; ) {
    // 买入时机
    if (prices[i] > prices[i + 1]) {
      i++
      continue
    }
    for (let j = i + 1; j < length; ) {
      if (prices[j] < prices[j + 1] && j < length - 1) {
        j++
        continue
      }
      earn += prices[j] - prices[i]
      i = j + 1
      break
    }
  }

  return earn
}
```