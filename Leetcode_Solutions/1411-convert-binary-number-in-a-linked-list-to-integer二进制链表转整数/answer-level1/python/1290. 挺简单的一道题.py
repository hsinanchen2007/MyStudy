### 解题思路
每一次计算的时候，把前面得到的所有数之和*2，再加上当前所指的数，如此操作一直到累积到最后一个值。

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getDecimalValue(self, head: ListNode) -> int:
        num = 0 
        while head != None:
            num = num*2 + head.val
            head = head.next
        return num
```