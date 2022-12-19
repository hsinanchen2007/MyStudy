```
object Solution {
  def reverse(head: ListNode): ListNode = {
    var last :ListNode= null
    var now = head
    var next: ListNode = null
    while(now != null){
      next = now.next
      now.next = last
      last = now
      now = next
    }
    return last
  }

  def isPalindrome(head: ListNode): Boolean = {
    var fast = head
    var slow = head
    while (fast != null && fast.next != null) {
      slow = slow.next
      fast = fast.next.next
    }
    //此时slow是分界点
    var pList = reverse(slow.next)
    var pOld = head
    while (pList != null) {
      if (pList.x != head.x) return false
      pList = pList.next
      pOld = pOld.next
    }
    return true
  }
}
```
