```scala
object Solution {
  def partition(head: ListNode, x: Int): ListNode = head match {
    case null => head
    case _ =>
      val dummy = new ListNode(-1)
      val newDummy = new ListNode(-1)
      dummy.next = head
      var cur = dummy
      var p = newDummy
      while (cur.next != null) {
        if (cur.next.x < x) {
          p.next = cur.next
          p = p.next
          cur.next = cur.next.next
          p.next = null
        } else cur = cur.next
      }
      p.next = dummy.next
      newDummy.next
  }
}
```
