```scala
object Solution {
  def maxUncrossedLines(A: Array[Int], B: Array[Int]): Int = {
    val dp = Array.ofDim[Int](A.length + 1, B.length + 1)
    A.indices.foreach(i => B.indices.foreach(j => {
      if (A(i) == B(j)) dp(i + 1)(j + 1) = dp(i)(j) + 1
      else dp(i + 1)(j + 1) = math.max(dp(i + 1)(j), dp(i)(j + 1))
    }))
    dp(A.length)(B.length)
  }
}
```
