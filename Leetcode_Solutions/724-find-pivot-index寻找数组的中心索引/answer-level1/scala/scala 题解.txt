```scala
object Solution {
  def pivotIndex(nums: Array[Int]): Int = {
    val len = nums.length
    var sum = 0
    var cur = 0
    for (i <- 0 until len) sum += nums(i)
    for (i <- 0 until len) {
      if (i == 0) cur = 0
      else cur += nums(i - 1)
      if (cur << 1 == sum - nums(i)) return i
    }
    -1
  }
}
```
