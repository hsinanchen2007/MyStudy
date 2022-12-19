```scala
object Solution {
  def numDistinct(s: String, t: String): Int = {
    val dp = Array.fill(t.length + 1, s.length + 1)(0)
    s.indices.foreach(i => dp(0)(i) = 1)
    (1 to t.length).foreach(i => dp(i)(0) = 0)
    (1 to t.length).foreach(i => (1 to s.length).foreach(j =>
      dp(i)(j) = dp(i)(j - 1) + (if (t(i - 1) == s(j - 1)) dp(i - 1)(j - 1) else 0)))
    dp(t.length)(s.length)
  }
}
```