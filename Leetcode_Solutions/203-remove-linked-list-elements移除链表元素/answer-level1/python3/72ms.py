```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeElements(self, head: ListNode, val: int) -> ListNode:
        first = head
        list1 = []
        while first != None:
            if first.val != val:
                list1.append(first.val)
            first = first.next
        l1 = ListNode(0)
        l1.next = head
        second = l1
        for i in list1:
            second = second.next
            second.val = i
        second.next = None
        l1 = l1.next
        return(l1)
```
