### 解题思路
先计算两条链的长度，让长的那条链的指针从头先走一个长度差，然后再一起向前走即可。

### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        p, q = headA, headB
        num1 = num2 = 0
        while p:
            p = p.next
            num1 += 1
        while q:
            q = q.next
            num2 += 1
        p, q = headA, headB
        if num1 < num2:
            for _ in range(num2 - num1):
                q = q.next
        elif num1 > num2:
            for _ in range(num1 - num2):
                p = p.next
        while p != q:
            p = p.next
            q = q.next
        return p
```