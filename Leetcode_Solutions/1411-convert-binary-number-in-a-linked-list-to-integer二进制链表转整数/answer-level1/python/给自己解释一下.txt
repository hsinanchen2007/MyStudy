### 解题思路
二进制位数每多一位 数字的大小翻一倍 是0直接乘2 是1乘2加1

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:
    def getDecimalValue(self, head: ListNode) -> int:
        sum = 0
        while head != None:  
            sum = sum * 2 + head.val # 相当于rec = rec<<1 | head.val
            head = head.next
        return sum
```