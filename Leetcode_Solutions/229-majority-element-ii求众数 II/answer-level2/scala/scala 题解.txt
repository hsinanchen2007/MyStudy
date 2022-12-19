```scala
import scala.collection.mutable.ListBuffer

object Solution {
  def majorityElement(nums: Array[Int]): List[Int] = {
    val res = new ListBuffer[Int]
    var a = 0
    var b = 0
    var cnt1 = 0
    var cnt2 = 0
    val n = nums.length
    nums.foreach(i => {
      if (i == a) cnt1 += 1
      else if (i == b) cnt2 += 1
      else if (cnt1 == 0) {
        a = i
        cnt1 = 1
      } else if (cnt2 == 0) {
        b = i
        cnt2 = 1
      } else {
        cnt1 -= 1
        cnt2 -= 1
      }
    })
    cnt1 = 0
    cnt2 = 0
    nums.foreach(i => if (i == a) cnt1 += 1 else if (i == b) cnt2 += 1)
    if (cnt1 > n / 3) res.append(a)
    if (cnt2 > n / 3) res.append(b)
    res.toList
  }
}
```
