> 11.26 python


```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        first = ListNode(-1)
        first.next = head
        second = first
        pre = first

        for _ in range(n):
            head = head.next

        while head:
            head = head.next
            second = second.next

        second.next = second.next.next

        return first.next

```