做了不少题了，发现很简单的题，官方都能吧 `O(n²)` 的解法优化成 `O(n)`的😎

```javascript []
/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
  if (prices.length === 0) {
    return 0
  }
  let res = 0
  let min = prices[0]

  for (const price of prices) {
    if (price < min) {
      min = price
      continue
    }

    if (res < price - min) {
      res = price - min
      continue
    }
  }

  return res
}
```