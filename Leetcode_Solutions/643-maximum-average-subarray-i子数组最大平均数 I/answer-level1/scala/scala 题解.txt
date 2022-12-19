```scala
object Solution {
  def findMaxAverage(nums: Array[Int], k: Int): Double = {
    var sum = 0.0
    (0 until k).foreach(i => sum += nums(i))
    var tmp = sum
    var j = 0
    (k until nums.length).foreach(i => {
      tmp += nums(i)
      tmp -= nums(j)
      j += 1
      if (tmp > sum) sum = tmp
    })
    sum / k
  }
}
```
