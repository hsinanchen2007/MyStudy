### 解题思路
仿照其他题主JS思路，双指针法

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def kthToLast(self, head: ListNode, k: int) -> int:
        slow = fast = head
        i = 0
        while i < k:
            fast = fast.next
            i += 1
        while fast:
            fast = fast.next
            slow = slow.next
        return slow.val
```