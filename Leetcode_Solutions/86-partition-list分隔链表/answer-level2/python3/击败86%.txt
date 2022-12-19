```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def partition(self, head: ListNode, x: int) -> ListNode:
        list1 = []
        list2 = []
        l1 = ListNode(0)
        l1.next = head
        first = l1.next
        while head != None:
            if head.val < x:
                list1.append(head.val)
            else:
                list2.append(head.val)
            head = head.next
        list1.extend(list2)
        for i in list1:
            first.val = i
            first =first.next
        l1 = l1.next
        return(l1)
```
