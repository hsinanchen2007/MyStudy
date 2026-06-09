时间复杂度O(2n) 空间复杂度O(1)
```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        reshead = ListNode(0)
        result = reshead
        while l1 != None and l2 != None:
            if l1.val <= l2.val:
                reshead.next = l1
                reshead = reshead.next
                l1 = l1.next
            else:
                reshead.next = l2 
                reshead = reshead.next
                l2 = l2.next
        if l1 != None:
            reshead.next = l1
        elif l2 != None:
            reshead.next = l2
        return result.next
```