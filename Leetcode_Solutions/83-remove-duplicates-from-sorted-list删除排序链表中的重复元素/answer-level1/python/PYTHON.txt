
### 代码

```python3
class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        List = head
        while head and head.next:
            if head.val == head.next.val:
                head.next = head.next.next
            else:
                head = head.next
        return List
```