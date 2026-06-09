```scala
object Solution {
  def reverseBetween(head: ListNode, m: Int, n: Int): ListNode = {
    val dummy = new ListNode(-1)
    var p = dummy
    dummy.next = head
    (0 until (m - 1)).foreach(_ => p = p.next)
    val cur = p.next
    (m until n).foreach(_ => {
      val tmp = cur.next
      cur.next = tmp.next
      tmp.next = p.next
      p.next = tmp
    })
    dummy.next
  }
}
```
