```scala
object Solution {
  def champagneTower(poured: Int, query_row: Int, query_glass: Int): Double = {
    val dp = Array.fill(101)(0.0)
    dp(0) = poured
    (1 to query_row).foreach(i => (i to 0 by -1).foreach(j => {
      dp(j) = 0.0.max((dp(j) - 1) / 2.0)
      dp(j + 1) += dp(j)
    }))
    1.0.min(dp(query_glass))
  }
}
```
