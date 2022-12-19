```scala
object Solution {
  def countPalindromicSubsequences(S: String): Int = {
    val M = 1e9.toInt + 7
    val dp = Array.ofDim[Int](S.length, S.length)
    S.indices.foreach(i => dp(i)(i) = 1)
    (1 until S.length).foreach(i => {
      (0 until S.length - i).foreach(j => {
        val k = j + i
        if (S(j) == S(k)) {
          var left = j + 1
          var right = k - 1
          while (left <= right && S(left) != S(j)) left += 1
          while (left <= right && S(right) != S(j)) right -= 1
          if (left > right) dp(j)(k) = dp(j + 1)(k - 1) * 2 + 2
          else if (left == right) dp(j)(k) = dp(j + 1)(k - 1) * 2 + 1
          else dp(j)(k) = dp(j + 1)(k - 1) * 2 - dp(left + 1)(right - 1)
        } else
          dp(j)(k) = dp(j)(k - 1) + dp(j + 1)(k) - dp(j + 1)(k - 1)
        dp(j)(k) = if (dp(j)(k) < 0) dp(j)(k) + M else dp(j)(k) % M
      })
    })
    dp(0)(S.length - 1)
  }
}
```

