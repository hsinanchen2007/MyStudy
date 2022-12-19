```scala
object Solution {
  def minMoves2(nums: Array[Int]): Int = {
    val t = nums.sorted
    t.map(i => math.abs(i - t(t.length / 2))).sum
  }
}
```
