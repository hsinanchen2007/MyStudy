```
class KthLargest(_k: Int, _nums: Array[Int]) {
  implicit val smallOrdering = Ordering[Int].reverse
  val heap = scala.collection.mutable.PriorityQueue[Int]()
  for (elem <- _nums) {
    add(elem)
  }
  def add(x: Int): Int = {
    if (heap.size < _k) {
      heap.enqueue(x)
    } else {
      if (heap.head < x) {
        heap.dequeue()
        heap.enqueue(x)
      }
    }
    heap.head
  }
}
```
