### 解题思路
scala解法如下

### 代码

```scala
object Solution {
  def maxProfit(prices: Array[Int]): Int = {
    var max = 0
    if (prices.length > 1) {
      for (i <- 0 until (prices.length)) {
        for (j <- i + 1 until prices.length) {
          if (prices(j) - prices(i) > max) {
            max = prices(j) - prices(i)
          }
        }
      }
      print(max)
      max
    } else {
      print(0)
      0
    }
  }
}
```