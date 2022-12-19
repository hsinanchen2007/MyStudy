### 解题思路


### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        if not head:
            return False
        fast, slow = head.next, head
        try:
            while fast:
                if fast == slow:
                    return True
                fast, slow = fast.next.next, slow.next
        except:
            return False
```