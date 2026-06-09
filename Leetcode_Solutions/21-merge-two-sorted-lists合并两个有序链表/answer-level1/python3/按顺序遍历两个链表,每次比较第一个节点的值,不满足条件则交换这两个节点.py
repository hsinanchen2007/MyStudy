```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        if not l2:
            return l1
        head=ListNode(0)
        head.next=l1
        p=head
        q=l2
        while p.next and q:
            if p.next.val>q.val:
                t=p.next
                p.next=q
                q=t
            p=p.next
        p.next=q
        return head.next
```
