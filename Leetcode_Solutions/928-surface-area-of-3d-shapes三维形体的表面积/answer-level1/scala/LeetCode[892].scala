```
object Solution {
  def surfaceArea(grid: Array[Array[Int]]): Int = {
    var sum = 0
    for (i <- grid.indices) {
      for (j <- grid(0).indices) {
        if (grid(i)(j) > 0) {
          sum += 2 + 4 * grid(i)(j)
          if (i >= 1) sum -= math.min(grid(i - 1)(j), grid(i)(j)) * 2
          if (j >= 1) sum -= math.min(grid(i)(j - 1), grid(i)(j)) * 2
        }
      }
    }
    return sum
  }
}
```
