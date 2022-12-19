```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        new = ListNode(0)
        p1, p2, pn = l1, l2, new
        while p1 != None and p2 != None:
            if p1.val == p2.val:
                pn.next = p1
                pn = p1
                p1 = p1.next
                pn.next = p2
                pn = p2
                p2 = p2.next
            elif p1.val > p2.val:
                pn.next = p2
                pn = p2
                p2 = p2.next
            else:
                pn.next = p1
                pn = p1
                p1 = p1.next
        if p1 != None:
            pn.next = p1
        if p2 != None:
            pn.next = p2
        return new.next
```
