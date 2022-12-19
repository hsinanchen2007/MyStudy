```
object Solution {
  def maxProfit(prices: Array[Int]): Int= {
    var total_sum = 0
    var profit = 0
    var min = Int.MaxValue
    for (item <- prices) {
      if (item < min) min = item
      if ((item - min) > profit) profit = item - min
      else {
        total_sum = total_sum + profit
        profit = 0
        min = item
      }
    }
    return total_sum + profit
  }
}
```
