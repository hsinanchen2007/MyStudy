```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def sortList(self, head: ListNode) -> ListNode:
        list1 = []
        while head != None:
            list1.append(head.val)
            head = head.next
        list1.sort()
        t1 = ListNode(0)
        first = t1
        for j in list1:
            second = ListNode(j)
            first.next = second
            first = first.next
        t1 = t1.next
        return(t1)
```
