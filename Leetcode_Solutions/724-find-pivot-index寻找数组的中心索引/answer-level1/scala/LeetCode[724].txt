```
object Solution {
  def pivotIndex(nums: Array[Int]): Int = {
    val total = nums.sum
    var sum = 0
    for (i <- nums.indices) {
      if( sum + nums(i) + sum == total ) return i
      sum += nums(i)
    }
    return -1
  }
}
```
