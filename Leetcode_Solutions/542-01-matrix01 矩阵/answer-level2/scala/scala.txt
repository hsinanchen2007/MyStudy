```scala
object Solution {
  def updateMatrix(matrix: Array[Array[Int]]): Array[Array[Int]] = {
    val res = Array.ofDim[Int](matrix.length, matrix(0).length)
    res.foreach(i => i.indices.foreach(j => i(j) = Int.MaxValue - 1))
    res.indices.foreach(i => matrix(0).indices.foreach(j => {
      if (matrix(i)(j) == 0) res(i)(j) = 0
      else {
        if (i > 0) res(i)(j) = res(i)(j).min(res(i - 1)(j) + 1)
        if (j > 0) res(i)(j) = res(i)(j).min(res(i)(j - 1) + 1)
      }
    }))
    (matrix.length - 1 to 0 by -1).foreach(i => (matrix(0).length - 1 to 0 by -1).foreach(j => {
      if (res(i)(j) != 0 && res(i)(j) != 1) {
        if (i < matrix.length - 1) res(i)(j) = res(i)(j).min(res(i + 1)(j) + 1)
        if (j < matrix(0).length - 1) res(i)(j) = res(i)(j).min(res(i)(j + 1) + 1)
      }
    }))
    res
  }
}
```