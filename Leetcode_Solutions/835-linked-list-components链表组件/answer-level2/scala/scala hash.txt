```scala
import scala.collection.mutable

object Solution {
  def numComponents(head: ListNode, G: Array[Int]): Int = {
    var res = 0
    var h = head
    val s = new mutable.HashSet[Int]()
    G.foreach(i => s.add(i))
    while (h != null) {
      if (s.contains(h.x) && (h.next == null || !s.contains(h.next.x))) res += 1
      h = h.next
    }
    res
  }
}
```
