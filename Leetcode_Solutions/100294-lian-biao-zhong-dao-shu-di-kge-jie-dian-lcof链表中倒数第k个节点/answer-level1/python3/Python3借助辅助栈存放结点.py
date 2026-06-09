```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getKthFromEnd(self, head: ListNode, k: int) -> ListNode:
        ls = []
        if not head:
            return 
        while head:
            ls.append(head)
            head = head.next
        return ls[-k]
```
