### 解题思路
Python iteratively

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        p = None
        while head:
            head.next, p, head = p, head, head.next
        return p
```