```scala
object Solution {
  def minDistance(word1: String, word2: String): Int = {
    val dp = Array.fill(word1.length + 1, word2.length + 1)(0)
    (0 to word1.length).foreach(i => (0 to word2.length).foreach(j =>
      if (i == 0 || j == 0) dp(i)(j) = i.max(j)
      else {
        if (word1(word1.length - i) == word2(word2.length - j)) dp(i)(j) = dp(i - 1)(j - 1)
        else dp(i)(j) = 1 + dp(i - 1)(j).min(dp(i)(j - 1)).min(dp(i - 1)(j - 1))
      }))
    dp(word1.length)(word2.length)
  }
}
```
