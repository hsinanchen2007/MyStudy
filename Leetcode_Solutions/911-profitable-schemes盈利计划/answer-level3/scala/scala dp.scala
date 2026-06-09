由题可得：$dp(i)(j)(k)$ 表示最多干 $i$ 个任务，$j$ 个人，$k$ 利润，求方案总数。
第 $i$ 个任务，只与 $i-1$ 个任务的分配方案有关，所以可以降一个维度
```scala
object Solution {
  def profitableSchemes(G: Int, P: Int, group: Array[Int], profit: Array[Int]): Int = {
    var res = 0
    val M = (1e9 + 7).toInt
    val dp = Array.ofDim[Int](G + 1, P + 1)
    dp(0)(0) = 1
    (1 to group.length).foreach(i => {
      val g = group(i - 1)
      val p = profit(i - 1)
      (G to g by -1).foreach(j => (P to 0 by -1).foreach(k => dp(j)(k) = (dp(j)(k) + dp(j - g)(math.max(0, k - p))) % M))
    })
    (0 to G).foreach(i => res = (res + dp(i)(P)) % M)
    res
  }
}
```
