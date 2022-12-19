```scala
object Solution {
  def repeatedSubstringPattern(s: String): Boolean = {
    val dp = Array.fill(s.length + 1)(0)
    var i = 1
    var j = 0
    while (i < s.length) {
      if (s(i) == s(j)) {
        i += 1
        j += 1
        dp(i) = j
      } else if (j == 0) i += 1
      else j = dp(j)
    }
    (dp(s.length) > 0) && (dp(s.length) % (s.length - dp(s.length)) == 0)
  }
}
```
