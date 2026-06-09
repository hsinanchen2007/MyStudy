```scala
import scala.collection.mutable

object Solution {
  def addTwoNumbers(l1: ListNode, l2: ListNode): ListNode = {
    var t1 = l1
    var t2 = l2
    val s1 = new mutable.Stack[Int]()
    val s2 = new mutable.Stack[Int]()
    while (t1 != null) {
      s1.push(t1.x)
      t1 = t1.next
    }
    while (t2 != null) {
      s2.push(t2.x)
      t2 = t2.next
    }
    var sum = 0
    var res = new ListNode(0)
    while (s1.nonEmpty || s2.nonEmpty) {
      if (s1.nonEmpty) {
        sum += s1.top
        s1.pop
      }
      if (s2.nonEmpty) {
        sum += s2.top
        s2.pop
      }
      res.x = sum % 10
      val head = new ListNode(sum / 10)
      head.next = res
      res = head
      sum /= 10
    }
    if (res.x == 0) res.next else res
  }
}
```
