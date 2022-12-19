```scala
object Solution {
  def singleNumber(nums: Array[Int]): Array[Int] = {
    val res = new Array[Int](2)
    var xor = 0
    nums.foreach(i => xor ^= i)
    val k = xor & (-xor)
    nums.foreach(i => if ((i & k) == 0) res(0) ^= i else res(1) ^= i)
    res
  }
}
```
