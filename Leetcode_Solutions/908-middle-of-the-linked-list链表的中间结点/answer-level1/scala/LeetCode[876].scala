```
object Solution {
  def middleNode(head: ListNode): ListNode = {
    var slow = head
    var fast = head
    while (fast != null && fast.next != null) {
      slow = slow.next
      fast = fast.next
      if (fast != null) {
        fast = fast.next
      }
    }
    slow
  }
}
```
