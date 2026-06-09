```
object Solution {
  def minMoves(nums: Array[Int]): Int = {
    var num = 0
    val min = nums.min
    for (item <- nums) {
      num += item - min
    }
    return num
  }
}
```
