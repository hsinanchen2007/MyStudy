```
object Solution {
  def getRow(rowIndex: Int): List[Int] = {
    val arr = Array.ofDim[Int](rowIndex + 1)
    for (i <- 0 to rowIndex) {
      for (j <- (0 to i).reverse) {
        if (i == j) arr(j) = 1
        else if (j == 0) arr(j) = 1
        else arr(j) = arr(j) + arr(j - 1)
      }
    }
    return arr.toList
  }
}
```
