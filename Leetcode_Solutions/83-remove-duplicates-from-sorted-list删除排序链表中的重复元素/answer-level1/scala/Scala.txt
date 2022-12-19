Scala的链表好难理解

/**
 * Definition for singly-linked list.
 * class ListNode(var _x: Int = 0) {
 *   var next: ListNode = null
 *   var x: Int = _x
 * }
 */
object Solution {
    def deleteDuplicates(head: ListNode): ListNode = {
    var cur = head
    while (cur != null && cur.next != null) {
      if (cur.next._x == cur._x) {
        val node = cur.next
        cur.next = node.next
        node.next = null
      } else {
        cur = cur.next
      }
    }
    head
    }
}