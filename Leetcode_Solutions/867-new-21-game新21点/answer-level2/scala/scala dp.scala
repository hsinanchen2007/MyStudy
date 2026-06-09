```scala
object Solution {
  def new21Game(N: Int, K: Int, W: Int): Double = {
    if (K == 0 || N >= K + W) return 1.0
    val dp = Array.fill(N + 1)(0.0)
    dp(0) = 1.0
    var sum = 1.0
    var res = 0.0
    (1 to N).foreach(i => {
      dp(i) = sum / W
      if (i < K) sum += dp(i) else res += dp(i)
      if (i - W >= 0) sum -= dp(i - W)
    })
    res
  }
}
```
