
```python []
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        p1,p2=l1,l2
        if not p1:
            return p2
        elif not p2:
            return p1
        if p1.val<=p2.val:
            p1.next=self.mergeTwoLists(p1.next,p2)
            return p1
        else:
            p2.next=self.mergeTwoLists(p1,p2.next)
            return p2
                
```
