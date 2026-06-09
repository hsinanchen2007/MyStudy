### 解题思路
很清晰的题，之前本来想俩循环套着m*n的，果然时间超了

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
        temp = {}
        while headA:
            temp[headA] = 1
            headA = headA.next
        while headB:
            if headB in temp:
                return headB
            headB=headB.next
        return None
```