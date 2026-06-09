```scala
object Solution {
  def isInterleave(s1: String, s2: String, s3: String): Boolean = {
    if (s1.length + s2.length != s3.length) return false
    val dp = Array.ofDim[Boolean](s1.length + 1, s2.length + 1)
    (0 to s1.length).foreach(i => {
      (0 to s2.length).foreach(j => {
        if (i == 0 && j == 0) dp(i)(j) = true
        else if (i == 0) dp(i)(j) = dp(i)(j - 1) && (s2(j - 1) == s3(i + j - 1))
        else if (j == 0) dp(i)(j) = dp(i - 1)(j) && (s1(i - 1) == s3(i + j - 1))
        else dp(i)(j) = (dp(i - 1)(j) && (s1(i - 1) == s3(i + j - 1))) || (dp(i)(j - 1) && (s2(j - 1) == s3(i + j - 1)))
      })
    })
    dp(s1.length)(s2.length)
  }
}
```
