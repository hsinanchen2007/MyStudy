```scala
import scala.collection.mutable

class MedianFinder() {

  private val small = new mutable.PriorityQueue[Long]()
  private val large = new mutable.PriorityQueue[Long]()

  def addNum(num: Int) {
    small.enqueue(num)
    large.enqueue(-small.head)
    small.dequeue
    if (small.size < large.size) {
      small.enqueue(-large.head)
      large.dequeue
    }
  }

  def findMedian(): Double = if (small.size > large.size) small.head else 0.5 * (small.head - large.head)

}
```