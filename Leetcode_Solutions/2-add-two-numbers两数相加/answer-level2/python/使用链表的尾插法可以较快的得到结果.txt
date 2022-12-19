### 解题思路
此处撰写解题思路

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        num = 0
        r = l = ListNode(None)
        while l1 or l2:
            if l1:
                num += l1.val
                l1 = l1.next
            if l2:
                num += l2.val
                l2 = l2.next
            r.next = ListNode(num % 10)
            r = r.next
            num = num // 10
        if num:
            r.next = ListNode(1)
        return l.next
```