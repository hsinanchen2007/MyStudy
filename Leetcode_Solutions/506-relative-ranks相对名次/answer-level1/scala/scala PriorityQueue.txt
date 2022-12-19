```scala
import scala.collection.mutable

object Solution {
  def findRelativeRanks(nums: Array[Int]): Array[String] = {
    var cnt = 1
    val res = Array.fill(nums.length)("")
    val q = new mutable.PriorityQueue[(Int, Int)]()
    nums.indices.foreach(i => q.enqueue((nums(i), i)))
    nums.indices.foreach(_ => {
      val idx = q.head._2
      q.dequeue
      cnt match {
        case 1 => res(idx) = "Gold Medal"
        case 2 => res(idx) = "Silver Medal"
        case 3 => res(idx) = "Bronze Medal"
        case _ => res(idx) = cnt.toString
      }
      cnt += 1
    })
    res
  }
}
```
