```scala
import scala.util.control.Breaks._

object Solution {
  def findNumberOfLIS(nums: Array[Int]): Int = {
    var res = 0
    var mx = 0
    val len = new Array[Int](nums.length)
    val cnt = new Array[Int](nums.length)
    len.indices.foreach(i => len(i) = 1)
    cnt.indices.foreach(i => cnt(i) = 1)

    nums.indices.foreach(i => {
      (0 until i).foreach(j => {
        breakable {
          if (nums(i) <= nums(j)) break
          if (len(i) == len(j) + 1) cnt(i) += cnt(j)
          else if (len(i) < len(j) + 1) {
            len(i) = len(j) + 1
            cnt(i) = cnt(j)
          }
        }
      })
      mx = math.max(mx, len(i))
    })

    nums.indices.foreach(i => if (mx == len(i)) res += cnt(i))
    res
  }
    
}
```
