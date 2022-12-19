```scala
object Solution {
  def minDeletionSize(A: Array[String]): Int = {
    val dp = Array.fill(A(0).length)(1)
    A(0).indices.foreach(i => (0 until i).foreach(j => if (A.forall(k => k(j) <= k(i))) dp(i) = dp(i).max(dp(j) + 1)))
    A(0).length - dp.max
  }

  def func(arr: Array[Array[Int]]): Int = {
    val A = arr.map(_.max)
    val B = arr(0).indices.toArray.map(j => arr.indices.map(i => arr(i)(j)).max)
    val d = arr.indices.flatMap(i => arr(i).indices.map(j => A(i).min(B(j)) - arr(i)(j)))
    d.sum
  }
}
```
