```scala
object Solution {
  def checkSubarraySum(nums: Array[Int], k: Int): Boolean = {
    nums.indices.foreach(i => {
      var sum = nums(i)
      ((i + 1) until nums.length).foreach(j => {
        sum += nums(j)
        if (sum == k) return true
        if (k != 0 && sum % k == 0) return true
      })
    })
    false
  }
}
```
