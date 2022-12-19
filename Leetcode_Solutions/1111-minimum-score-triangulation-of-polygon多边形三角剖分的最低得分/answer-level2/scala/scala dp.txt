```scala
object Solution {
  def minScoreTriangulation(A: Array[Int]): Int = {
    val dp = Array.fill(A.length, A.length)(Int.MaxValue)
    A.indices.foreach(i => dp(i)((i + 1) % A.length) = 0)
    (2 until A.length).foreach(i => A.indices.foreach(j => {
      val t = (j + i) % A.length
      var k = (j + 1) % A.length
      while (k != t) {
        dp(j)(t) = dp(j)(t).min(dp(j)(k) + dp(k)(t) + A(j) * A(k) * A(t))
        k = (k + 1) % A.length
      }
    }))
    dp(0)(A.length - 1)
  }
}
```
