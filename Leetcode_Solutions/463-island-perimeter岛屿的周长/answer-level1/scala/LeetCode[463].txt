```
object Solution {
  def ajecent(grid: Array[Array[Int]], i: Int, j: Int, coli: Int, colj: Int): Int = {
    var num = 0
    num += (if (i - 1 >= 0 && grid(i - 1)(j) == 1) 1 else 0)
    num += (if (i + 1 <= coli - 1 && grid(i + 1)(j) == 1) 1 else 0)
    num += (if (j - 1 >= 0 && grid(i)(j - 1) == 1) 1 else 0)
    num += (if (j + 1 <= colj - 1 && grid(i)(j + 1) == 1) 1 else 0)
    num
  }

  def islandPerimeter(grid: Array[Array[Int]]): Int = {
    val col1 = grid.length
    if (col1 == 0) return 0
    val col2 = grid(0).length

    var i = 0
    var j = 0

    var num = 0
    for (i <- 0 until col1; j <- 0 until col2) {
      if (grid(i)(j) == 1) {
        num += 4
        num -= ajecent(grid, i, j, col1, col2)
      }
    }
    num
  }
}
```
