```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        if head.next == None:
            return None
        p1, p2 = head, head
        while n > 0 and p2.next != None:
            p2 = p2.next
            n -= 1
        if n > 0:
            return head.next
        while p2.next != None:
            p1 = p1.next
            p2 = p2.next
        p1.next = p1.next.next
        return head
```
