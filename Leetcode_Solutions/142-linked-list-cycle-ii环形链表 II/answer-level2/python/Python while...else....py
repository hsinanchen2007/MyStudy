看到一个while else的用法，放在这道题还是挺合适的

```python
class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return None

        slow, fast = head.next, head.next.next
        while slow != fast:
            if not fast or not fast.next:
                return None
            slow, fast = slow.next, fast.next.next
        
        else:
            while head != slow:
                head, slow = head.next, slow.next
            
            return head
```