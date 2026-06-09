```scala
import scala.collection.mutable

object Solution {
  def findMaxLength(nums: Array[Int]): Int = {
    var res = 0
    var sum = 0
    val m = new mutable.HashMap[Int, Int]()
    m.put(0, -1)
    nums.indices.foreach(i => {
      sum += (nums(i) << 1) - 1
      if (m.contains(sum)) res = math.max(res, i - m(sum))
      else m(sum) = i
    })
    res
  }
}
```
