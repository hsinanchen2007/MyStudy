```
class Solution:
    def kthToLast(self, head: ListNode, k: int) -> int:
        slow = head
        fast = head
        while k > 0:
            fast = fast.next
            k -= 1
        while fast:
            fast = fast.next
            slow = slow.next
        return slow.val
```
