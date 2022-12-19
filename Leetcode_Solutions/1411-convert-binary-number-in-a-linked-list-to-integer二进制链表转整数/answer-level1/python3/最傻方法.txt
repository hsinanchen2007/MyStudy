### 解题思路

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getDecimalValue(self, head: ListNode) -> int:

        res = 0
        if head is None:
            return None
        while head:
            res = res*2 +head.val
            head = head.next
        return res

```