```scala
object Solution {
  def rob(nums: Array[Int]): Int = {
    if (nums.length <= 1) return if (nums.isEmpty) 0 else nums(0)
    func(nums, 0, nums.length - 1).max(func(nums, 1, nums.length))
  }

  def func(nums: Array[Int], left: Int, right: Int): Int = {
    var even = 0
    var odd = 0
    (left until right).foreach(i => if (i % 2 == 0) even = (even + nums(i)).max(odd) else odd = even.max(odd + nums(i)))
    even.max(odd)
  }
}
```
