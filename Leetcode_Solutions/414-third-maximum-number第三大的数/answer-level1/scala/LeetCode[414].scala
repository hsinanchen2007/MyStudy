```
object Solution {
  def thirdMax(nums: Array[Int]): Int = {
    val l: Array[Int] = nums.distinct.sorted
    if (l.length < 3) return l(l.length - 1)
    else l(l.length - 3)
  }
}
```
