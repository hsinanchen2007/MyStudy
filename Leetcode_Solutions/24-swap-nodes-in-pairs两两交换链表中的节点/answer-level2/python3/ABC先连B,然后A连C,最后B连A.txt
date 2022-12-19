```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        n=ListNode(-1)
        n.next=head
        t=n
        while head and head.next:
            t.next=head.next
            head.next=head.next.next
            t.next.next=head
            head=head.next
            t=t.next.next
        return n.next
```
