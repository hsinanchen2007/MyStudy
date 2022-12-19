```scala
import scala.collection.mutable
import scala.collection.mutable.ArrayBuffer

object Solution {
  def mincostToHireWorkers(quality: Array[Int], wage: Array[Int], K: Int): Double = {
    var res = Double.MaxValue
    var sum = 0.0
    val q = new mutable.PriorityQueue[Int]()
    val worker = new ArrayBuffer[(Double, Int)]()
    quality.indices.foreach(i => worker.append((wage(i).toDouble / quality(i), quality(i))))
    val t = worker.sorted
    t.foreach(i => {
      sum += i._2
      q.enqueue(i._2)
      if (q.size > K) {
        sum -= q.head
        q.dequeue
      }
      if (q.size == K) res = res.min(sum * i._1)
    })
    res
  }
}
```
