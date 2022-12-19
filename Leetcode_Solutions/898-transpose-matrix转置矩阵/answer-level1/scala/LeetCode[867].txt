```
object Solution {
  def transpose(A: Array[Array[Int]]): Array[Array[Int]] = {
    val rows = A.length
    val cols = A(0).length
    val ret = Array.ofDim[Int](cols, rows)

    for (i <- A.indices) {
      for (j <- A(0).indices) {
        ret(j)(i) = A(i)(j)
      }
    }
    ret
  }
}
```


```
object Solution {
  def transpose(A: Array[Array[Int]]): Array[Array[Int]] = {
    A.transpose
  }
}
```
