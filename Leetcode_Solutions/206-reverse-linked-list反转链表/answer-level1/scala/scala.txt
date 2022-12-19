```scala
/**
 * Definition for singly-linked list.
 * class ListNode(var _x: Int = 0) {
 *   var next: ListNode = null
 *   var x: Int = _x
 * }
 */
object Solution {
  def reverseList(head: ListNode): ListNode = {
    if (head == null || head.next == null) return head
    val cur = reverseList(head.next)
    head.next.next = head
    head.next = null
    cur
  }
}
```