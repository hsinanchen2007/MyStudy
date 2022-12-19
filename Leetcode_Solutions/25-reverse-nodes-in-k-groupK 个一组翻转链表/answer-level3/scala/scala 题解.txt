```scala
object Solution {
  def reverseKGroup(head: ListNode, k: Int): ListNode = {
    val g = new ListNode(0)
    if (!length(head, k)) head
    else {
      g.next = reverse(head, k)
      var p = g.next
      (1 until k).foreach(_ => p = p.next)
      p.next = reverseKGroup(p.next, k)
      g.next
    }
  }

  def reverse(head: ListNode, k: Int): ListNode = {
    var t = head
    (1 until k).foreach(_ => t = t.next)
    var p = head
    (1 until k).foreach(_ => {
      val tmp = p.next
      p.next = t.next
      t.next = p
      p = tmp
    })
    p
  }

  @scala.annotation.tailrec
  def length(head: ListNode, len: Int): Boolean = len match {
    case 0 => true
    case _ => head match {
      case null => if (len == 0) true else false
      case _ => length(head.next, len - 1)
    }
  }
}
```
