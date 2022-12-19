```scala
object Solution {
  def splitArray(nums: Array[Int], m: Int): Int = {
    val sums = Array.fill(nums.length + 1)(0)
    val dp = Array.fill(m + 1, nums.length + 1)(Int.MaxValue)
    dp(0)(0) = 0
    (1 to nums.length).foreach(i => sums(i) = sums(i - 1) + nums(i - 1))
    (1 to m).foreach(i => (1 to nums.length).foreach(j => (i - 1 until j).foreach(k => dp(i)(j) = dp(i)(j).min(dp(i - 1)(k).max(sums(j) - sums(k))))))
    dp(m)(nums.length)
  }
}
```