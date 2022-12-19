```scala
import scala.collection.mutable

object Solution {
  def minRefuelStops(target: Int, startFuel: Int, stations: Array[Array[Int]]): Int = {
    var res = 0
    var i = 0
    var s = startFuel
    val q = new mutable.PriorityQueue[Int]()
    while (s < target) {
      while (i < stations.length && stations(i)(0) <= s) {
        q.enqueue(stations(i)(1))
        i += 1
      }
      if (q.isEmpty) return -1
      s += q.head
      q.dequeue
      res += 1
    }
    res
  }
}
```
