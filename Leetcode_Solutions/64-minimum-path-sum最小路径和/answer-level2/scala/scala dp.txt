```scala
object Solution {
  def minPathSum(grid: Array[Array[Int]]): Int = {
    if (grid.isEmpty || grid(0).isEmpty) return 0
    val dp = Array.fill(grid(0).length)(Int.MaxValue)
    dp(0) = 0
    grid.indices.foreach(i => grid(i).indices.foreach(j => if (j == 0) dp(j) += grid(i)(j) else dp(j) = grid(i)(j) + dp(j).min(dp(j - 1))))
    dp(grid(0).length - 1)
  }
}
```
