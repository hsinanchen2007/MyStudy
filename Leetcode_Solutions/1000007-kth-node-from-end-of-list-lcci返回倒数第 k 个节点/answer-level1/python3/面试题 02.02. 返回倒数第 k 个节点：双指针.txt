
```python []
class Solution:
    def kthToLast(self, head: ListNode, k: int) -> int:
        tmp = head
        for _ in range(1, k):
            tmp = tmp.next
        while tmp.next:
            head = head.next
            tmp = tmp.next
        return head.val
```