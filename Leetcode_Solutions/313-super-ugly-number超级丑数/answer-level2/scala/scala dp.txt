```scala
object Solution {
  def nthSuperUglyNumber(n: Int, primes: Array[Int]): Int = {
    val dp = Array.fill(n)(1)
    val idx = Array.fill(primes.length)(0)
    (1 until n).foreach(i => {
      dp(i) = Int.MaxValue
      primes.indices.foreach(j => dp(i) = dp(i).min(dp(idx(j)) * primes(j)))
      primes.indices.foreach(j => if (dp(i) == dp(idx(j)) * primes(j)) idx(j) += 1)
    })
    dp.last
  }
}
```
