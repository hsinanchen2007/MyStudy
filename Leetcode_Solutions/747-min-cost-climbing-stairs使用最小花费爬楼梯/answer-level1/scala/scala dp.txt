```scala
object Solution {
  def minCostClimbingStairs(cost: Array[Int]): Int = {
    var a = 0
    var b = 0
    cost.foreach(i => {
      val t = a.min(b) + i
      a = b
      b = t
    })
    a.min(b)
  }
}
```
