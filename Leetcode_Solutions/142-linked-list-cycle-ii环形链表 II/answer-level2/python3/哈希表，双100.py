一趟遍历，时间复杂度O(n)。

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        record = {}
        while head:
            if record.get(head,0):
                return head
            record[head] = 1
            head = head.next
        return None
```