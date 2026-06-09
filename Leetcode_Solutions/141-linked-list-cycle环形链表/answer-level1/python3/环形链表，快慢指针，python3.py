### 解题思路
fast步长为2，slow步长为1，如果是环形链表，fast会和slow相遇

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
        fast = head
        slow = head
        while True:
            if not fast or not slow:
                return False
            if not fast.next or not slow.next:
                return False
            fast = fast.next.next
            slow = slow.next
            if slow == fast:
                return True

```