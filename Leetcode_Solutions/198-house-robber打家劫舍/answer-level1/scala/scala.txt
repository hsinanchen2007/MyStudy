这scala也太卑微了吧，那么慢。。。。。

```
object Rob {

  /**
   * 执行用时 : 500 ms , 在所有 Scala 提交中击败了 31.58% 的用户
    * 内存消耗 : 52.4 MB , 在所有 Scala 提交中击败了 14.29% 的用户
    * by xiaof
   */
  def solution(nums: Array[Int]): Int = {
    if (nums == null || nums.length <= 0) return 0
    //计算公式是判断当前这户是否需要偷窃，如果需要那么前一家不能偷，如果不需要偷，那么前一家可以偷
    //dp[i] = max {dp[i-1], dp[i-2] + curval}
    var dp = new Array[Int](nums.length + 1)
    dp(0) = 0
    dp(1) = nums(0)
    for (i <- 2 to nums.length) {
      dp(i) = Math.max(dp(i - 1), dp(i - 2) + nums(i - 1))
    }
    dp(nums.length)
  }

  def main(args: Array[String]): Unit = {
    val nums1 = Array(1,2,3,1)
    println(solution(nums1))

  }
}
```

