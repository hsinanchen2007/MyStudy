```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        l1 = ListNode(0)
        l1.next = head
        first = l1
        while first.next != None and first.next.next != None:
            aa = first.next.val
            bb = first.next.next.val
            first.next.val = bb
            first.next.next.val = aa
            first = first.next.next
        l1 = l1.next
        return(l1)
```
