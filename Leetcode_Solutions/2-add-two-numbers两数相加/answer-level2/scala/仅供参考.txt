/**
 * Definition for singly-linked list.
 * class ListNode(var _x: Int = 0) {
 *   var next: ListNode = null
 *   var x: Int = _x
 * }
 */
object Solution {
    def addTwoNumbers(l1: ListNode, l2: ListNode): ListNode = {
        var carry = 0;
    var dummyNode: ListNode = new ListNode
    var head = dummyNode
    var a: Int = 0
    var b: Int = 0
    var sum: Int = 0

    var l11 = l1
    var l22 = l2

    while (l11 != null || l22 != null || carry != 0) {
      l11 match {
        case null => a = 0
        case _ => a = l11.x
      }

      if (l22 != null) {
        b = l22.x
      } else {
        b = 0
      }

      sum = a + b + carry

      head.next = new ListNode(sum % 10)
      head = head.next

      carry = sum / 10

      if (l11 != null) {
        l11 = l11.next
      }
      
      if (l22 != null){
        l22 = l22.next
      }
    }
    dummyNode.next
    }
}