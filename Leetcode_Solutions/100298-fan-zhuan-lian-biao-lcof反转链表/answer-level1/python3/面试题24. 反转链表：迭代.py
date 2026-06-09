
```python []
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        ans = None
        while head:
            head.next, ans, head = ans, head, head.next
        return ans
```