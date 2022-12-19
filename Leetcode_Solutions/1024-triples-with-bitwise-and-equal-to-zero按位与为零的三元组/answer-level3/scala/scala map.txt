```scala
import scala.collection.mutable

object Solution {
  def countTriplets(A: Array[Int]): Int = {
    val m = mutable.HashMap[Int, Int]()
    (0 to A.max).foreach(i => A.foreach(x => if ((i & x) == 0) m.put(i, m.getOrElse(i, 0) + 1)))
    A.flatMap(x => A.map(y => m.getOrElseUpdate(x & y, 0))).toList.sum
  }
}
```
