奇数用一个头结点，偶数用一个头结点。然后将二者相连。
```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def oddEvenList(self, head: ListNode) -> ListNode:
        if not head:
            return head
        p=head
        t=q=p.next
        while q and q.next:
            p.next,q.next=p.next.next,q.next.next
            p,q=p.next,q.next
        p.next=t
        return head
```