```scala
object Solution {
  def bestRotation(A: Array[Int]): Int = {
    var res = 0
    val arr = Array.fill(A.length)(0)
    A.indices.foreach(i => arr((i - A(i) + 1 + A.length) % A.length) -= 1)
    (1 until A.length).foreach(i => {
      arr(i) += arr(i - 1) + 1
      res = if (arr(i) > arr(res)) i else res
    })
    res
  }
}
```
