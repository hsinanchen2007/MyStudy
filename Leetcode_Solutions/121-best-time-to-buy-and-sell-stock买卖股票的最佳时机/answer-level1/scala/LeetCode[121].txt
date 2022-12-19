```
object Solution {
    def maxProfit(prices: Array[Int]): Int = {
      var minPrice = Int.MaxValue
      var profit = 0
      if (prices==null || prices.size == 0 ) return 0 
      for (item <- prices) {
        if(item < minPrice) minPrice = item 
        else if( item - minPrice  > profit ) profit = item - minPrice
      }
      return profit
    }
}
```
