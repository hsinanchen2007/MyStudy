
### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        def add(a,b,carry):
            if not (a or b):
                return ListNode(1) if carry else None
            a = a if a else ListNode(0)
            b = b if b else ListNode(0)
            val = a.val + b.val + carry
            carry = 1 if val>=10 else 0
            a.val = val%10
            a.next = add(a.next, b.next, carry)
            return a
        return add(l1, l2, 0)
```