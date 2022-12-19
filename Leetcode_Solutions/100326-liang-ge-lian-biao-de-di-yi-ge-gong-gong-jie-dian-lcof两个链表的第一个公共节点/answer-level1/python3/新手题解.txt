```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        na = 0
        nb = 0
        head = headA
        while head is not None:
            head = head.next
            na += 1
        head = headB
        while head is not None:
            head = head.next
            nb += 1
        if na > nb:
            for i in range(na-nb):
                headA = headA.next
        elif na < nb:
            for i in range(nb-na):
                headB = headB.next

        while headA is not None and headB is not None:
            if headA == headB:
                return headA
            headA = headA.next
            headB = headB.next
        return None
```
