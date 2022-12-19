效率最高的位运算，从高位还原二进制数
```
# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def getDecimalValue(self, head: ListNode) -> int:
        re = 0
        p = head
        while(p):
            re=re*2+p.val # 与re = re<<1|p.val等价，相当于还原了原序列
            p = p.next
        return re
```

