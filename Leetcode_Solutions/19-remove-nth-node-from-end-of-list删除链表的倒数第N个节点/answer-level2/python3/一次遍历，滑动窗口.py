```python
class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        end = head
        start = head
        for i in range(n):
            end = end.next
        if not end:
            return head.next

        while end.next:
            start = start.next
            end = end.next
        if start.next.next:
            start.next = start.next.next
        else:
            start.next = None

        return head
```
