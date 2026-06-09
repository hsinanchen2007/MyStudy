```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        list1 = []
        for i in lists:
            while i != None:
                list1.append(i.val)
                i = i.next
        list1.sort()
        l1 = ListNode(0)
        first = l1
        for j in list1:
            first.next = ListNode(j)
            first = first.next
        l1 = l1.next
        return(l1)
```
