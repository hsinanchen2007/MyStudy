### 解题思路
这个listnode的数据结构这卡了好久，用个res1来记录最开始的位置，后面就是按位相加就行了，这个代码还是有很多可以优化的地方的

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1, l2):
        advance = 0
        res = None
        res1 = None
        while l1 or l2:
            if l1 is not None: 
                val1 = l1.val
            else:
                val1 = 0
            if l2 is not None: 
                val2 = l2.val
            else:
                val2 = 0
            if val1 + val2 + advance >= 10:
                if res:
                    res.next = ListNode(val2 + val1 + advance - 10)
                    res = res.next
                else:
                    res = ListNode(val2 + val1 + advance -10)
                    res1 = res
                advance = 1
            else:
                if res:
                    res.next = ListNode(val2 + val1 + advance)
                    res = res.next
                else:
                    res = ListNode(val2 + val1 + advance)
                    res1 = res
                advance = 0
            if l1:
                l1 = l1.next
            if l2:
                l2 = l2.next
        if advance == 1:
            res.next = ListNode(advance)
        return res1
```