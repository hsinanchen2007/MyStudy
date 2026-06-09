### 解题思路
res = (res << 1) | head.val (syntactic sugar)
<=>
res *= 2
res += head.val
head = head.next

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
        while head:
            res *= 2
            res += head.val
            head = head.next
        
        return res
```