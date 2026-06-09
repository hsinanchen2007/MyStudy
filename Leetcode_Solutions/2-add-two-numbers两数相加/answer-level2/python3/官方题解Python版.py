### 解题思路
细节

### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        dummyHead = ListNode(0)
        p,q,cur = l1,l2,dummyHead
        carry = 0
        while p or q:
            if not p:
                x = 0
            else:
                x = p.val
            y = q.val if  q else 0
            Sum = x + y + carry
            carry = Sum//10 # aaaa
            cur.next = ListNode(Sum%10)
            cur = cur.next
            if p:
                p = p.next #if p else pass
            if q:
                q = q.next #if q else pass
        if carry:
            cur.next = ListNode(carry) 
        return dummyHead.next
```