### 解题思路
rt

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        a = b = 0
        base = 1   
        while l1:
            a += (l1.val * base)
            base *= 10
            l1 = l1.next
        base = 1
        while l2:
            b += (l2.val * base)
            base *= 10
            l2 = l2.next 
        a += b
        if a == 0:
            return ListNode(0)
        l3 = ListNode(0)
        head = l3
        while a != 0:
            l3.next = ListNode(a%10)
            a = a // 10
            l3 = l3.next
        return head.next



```