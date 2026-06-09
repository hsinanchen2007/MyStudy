

```python []
class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        ans = head
        while head and head.next:
            ans, head = ans.next, head.next.next
        return ans
```