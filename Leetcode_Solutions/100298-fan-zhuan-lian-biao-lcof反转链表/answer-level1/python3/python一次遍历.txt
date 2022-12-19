```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:

        result = None

        while head:
            value = ListNode(head.val)

            value.next = result
            result = value

            head = head.next 

        return result
```
