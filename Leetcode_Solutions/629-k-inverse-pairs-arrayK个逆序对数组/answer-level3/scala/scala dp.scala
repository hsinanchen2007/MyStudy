```scala
object Solution {
  def kInversePairs(n: Int, k: Int): Int = {
    val M = 1000000007
    val dp = Array.ofDim[Int](n + 1, k + 1)
    dp(0)(0) = 1
    (1 to n).foreach(i => {
      dp(i)(0) = 1
      (1 to k).foreach(j => {
        dp(i)(j) = (dp(i - 1)(j) + dp(i)(j - 1)) % M
        if (j >= i) dp(i)(j) = (dp(i)(j) - dp(i - 1)(j - i) + M) % M
      })
    })
    dp(n)(k)
  }
}
```
