```scala
import scala.collection.mutable

object Solution {
  def reorderList(head: ListNode): Unit = {
    if (head == null || head.next == null || head.next.next == null) return
    val st = new mutable.Stack[ListNode]()
    var cur = head
    while (cur != null) {
      st.push(cur)
      cur = cur.next
    }
    var cnt = (st.size - 1) / 2
    cur = head
    while (cnt > 0) {
      val t = st.top
      st.pop
      val next = cur.next
      cur.next = t
      t.next = next
      cur = next
      cnt -= 1
    }
    st.top.next = null
  }
}
```
