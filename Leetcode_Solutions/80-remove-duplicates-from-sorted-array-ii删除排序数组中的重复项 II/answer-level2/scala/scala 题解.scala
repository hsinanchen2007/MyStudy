```scala
object Solution {
  def removeDuplicates(nums: Array[Int]): Int = {
    var res = 0
    nums.foreach(i => {
      if (res < 2 || i > nums(res - 2)) {
        nums(res) = i
        res += 1
      }
    })
    res
  }
}
```
