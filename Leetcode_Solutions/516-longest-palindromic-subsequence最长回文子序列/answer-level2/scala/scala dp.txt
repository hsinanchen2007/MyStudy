```scala
object Solution {
  def longestPalindromeSubseq(s: String): Int = {
    val dp = Array.fill(s.length, s.length)(0)
    (0 until s.length).foreach(i => dp(i)(i) = 1)
    (s.length - 1 to 0 by -1).foreach(i => (i + 1 until s.length).foreach(j =>
      if (s(i) == s(j)) dp(i)(j) = dp(i + 1)(j - 1) + 2
      else dp(i)(j) = dp(i + 1)(j) max dp(i)(j - 1)))
    dp(0)(s.length - 1)
  }
}
```
