```scala
object Solution {
  def splitArraySameAverage(A: Array[Int]): Boolean = {
    val n = A.sum
    val flag = Array.ofDim[Boolean](A.length, n + 1)
    flag(0)(0) = true
    A.indices.foreach(i => {
      (A.length - 1 to 1 by -1).foreach(j => {
        (n until 0 by -1).foreach(k => {
          if (k >= A(i) && flag(j - 1)(k - A(i))) {
            flag(j)(k) = true
            if (k * A.length == j * n) return true
          }
        })
      })
    })
    false
  }
}
```
