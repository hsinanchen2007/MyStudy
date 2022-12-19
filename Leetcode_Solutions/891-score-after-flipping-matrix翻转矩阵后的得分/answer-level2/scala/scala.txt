```scala
object Solution {
  def matrixScore(A: Array[Array[Int]]): Int = {
    var res = (1 << (A(0).length - 1)) * A.length
    (1 until A(0).length).foreach(j => {
      var cnt = 0
      A.indices.foreach(i => cnt += (if (A(i)(j) == A(i)(0)) 1 else 0))
      res += cnt.max(A.length - cnt) * (1 << (A(0).length - 1 - j))
    })
    res
  }
}
```