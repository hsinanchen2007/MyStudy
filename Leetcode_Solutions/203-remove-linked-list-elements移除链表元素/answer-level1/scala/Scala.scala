/**
 * Definition for singly-linked list.
 * class ListNode(var _x: Int = 0) {
 *   var next: ListNode = null
 *   var x: Int = _x
 * }
 */
object Solution {
    def removeElements(head: ListNode, `val`: Int): ListNode = {

    val pre: ListNode = new ListNode(-1)
    pre.next = head
    var cur = pre

    while (cur != null && cur.next != null) {
      if (`val` == cur.next._x) {
        cur.next = cur.next.next
      } else {
        cur = cur.next
      }
    }
    pre.next
    }
}