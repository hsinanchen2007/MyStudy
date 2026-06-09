```scala
object Solution {
  def singleNumber(nums: Array[Int]): Int = {
    var sum = 0
    var res = 0
    for (i <- 0 until 32) {
      sum = 0
      for (n <- nums)
        if ((n >> i & 1) != 0) sum += 1
      if (sum % 3 != 0) res |= 1 << i
    }
    res
  }
}
```
