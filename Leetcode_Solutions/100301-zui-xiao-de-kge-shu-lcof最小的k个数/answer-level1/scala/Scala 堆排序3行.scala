```
object Solution {
  def getLeastNumbers(arr: Array[Int], k: Int): Array[Int] = {
    val heap = scala.collection.mutable.PriorityQueue.empty[Int].reverse
    arr.foreach(x => heap.enqueue(x))
    (0 until k).map(x => heap.dequeue()).toArray
  }
}
```
