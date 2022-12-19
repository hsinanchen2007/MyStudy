### 解题思路
在python中，对象赋值实际上是对象的引用。因此l3是ls的浅复制，两者指向同一个链表。

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        ls = ListNode(0)
        l3 = ls
        carry = 0
        while l1 or l2:
            val1 = l1.val if l1 else 0
            val2 = l2.val if l2 else 0
            val = val1 + val2 + carry
            if val >= 10:
                carry = 1
                val = val - 10
            else:
                carry = 0
            if l1: l1 = l1.next
            if l2: l2 = l2.next
            l3.next = ListNode(val)
            l3 = l3.next
        if carry > 0:
            l3.next = ListNode(1)
        return ls.next
```