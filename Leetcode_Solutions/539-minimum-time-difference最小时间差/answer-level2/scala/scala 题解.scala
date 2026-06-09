```scala
import scala.collection.mutable.ArrayBuffer

object Solution {
  def findMinDifference(timePoints: List[String]): Int = {
    var res = Int.MaxValue
    val nums = new ArrayBuffer[Int]()
    timePoints.foreach(i => {
      val h = i.substring(0, 2).toInt
      val m = i.substring(3).toInt
      nums.append(h * 60 + m)
    })
    val t = nums.sorted
    (1 until timePoints.length).foreach(i => res = math.min(res, t(i) - t(i - 1)))
    math.min(res, 1440 + t(0) - t.last)
  }
}
```
