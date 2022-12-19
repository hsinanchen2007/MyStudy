```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        first = head
        l1 = ListNode(0)
        l1.next = head
        second = l1
        list1 = []
        while first != None:
            if first.val not in list1:
                list1.append(first.val)
            first = first.next
        #print(list1)
        for i in list1:
            second = second.next
            second.val = i
        second.next = None
        l1 = l1.next
        return(l1)
```
