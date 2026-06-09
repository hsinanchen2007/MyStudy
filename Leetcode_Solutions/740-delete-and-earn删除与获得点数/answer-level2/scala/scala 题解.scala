```scala
object Solution {
  def deleteAndEarn(nums: Array[Int]): Int = {
    val res = Array.ofDim[Int](10001)
    nums.foreach(i => res(i) += i)
    (2 until 10001).foreach(i => res(i) = math.max(res(i - 1), res(i - 2) + res(i)))
    res(10000)
  }
}
```
