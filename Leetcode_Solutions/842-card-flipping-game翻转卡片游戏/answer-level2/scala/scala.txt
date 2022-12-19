```scala
import scala.collection.mutable

object Solution {
  def flipgame(fronts: Array[Int], backs: Array[Int]): Int = {
    var res = Int.MaxValue
    val s = new mutable.HashSet[Int]()
    fronts.indices.foreach(i => if (fronts(i) == backs(i)) s.add(fronts(i)))
    fronts.foreach(i => if (!s.contains(i)) res = res.min(i))
    backs.foreach(i => if (!s.contains(i)) res = res.min(i))
    if (res == Int.MaxValue) 0 else res
  }
}
```