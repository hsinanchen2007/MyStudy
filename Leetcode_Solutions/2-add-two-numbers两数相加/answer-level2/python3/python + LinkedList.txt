```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def sovle_rest(self, cur, l, carry):
        while l:
            l.val += carry
            carry, l.val = (l.val >= 10), l.val % 10
            cur.next = l
            cur, l = cur.next, l.next
        if carry == 1: cur.next = ListNode(int(carry))
        
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        tempHead = ListNode(0)
        cur, carry = tempHead, 0
        while l1 and l2:
            l1.val += l2.val + carry
            carry, l1.val = (l1.val >= 10), l1.val % 10
            cur.next = l1
            cur = cur.next
            l1, l2 = l1.next, l2.next
        if l1:
            self.sovle_rest(cur, l1, carry)
        elif l2:
            self.sovle_rest(cur, l2, carry)
        elif carry:
            cur.next = ListNode(1)
        return tempHead.next
```