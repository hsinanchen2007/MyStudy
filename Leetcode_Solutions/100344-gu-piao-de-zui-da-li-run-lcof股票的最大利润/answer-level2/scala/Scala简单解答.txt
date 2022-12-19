```
  /**
    * 每一天依据以前的最便宜价格和今日价格计算
    * 当天所能出售的最低价格和最高利润
    */
  def maxProfit(prices: Array[Int]): Int =
    prices.foldLeft((Int.MaxValue, 0)) { case ((minPrice, lastProfit), price) =>
      price.min(minPrice) -> lastProfit.max(price - minPrice)
    }._2
```
