### 解题思路
如题所述

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
        backA=headA
        backB=headB
        flag=0
        while flag<2:
            # print headA.val,headB.val
            if headA==headB:
                return headA
            if headA and headA.next:
                headA=headA.next
            else:
                flag+=1
                headA=backB
            if headB and headB.next:
                headB=headB.next
            else:
                headB=backA
        return None

       
```