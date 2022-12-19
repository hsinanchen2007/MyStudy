```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        l1 = ListNode(0)
        l1.next = head
        first = l1.next
        second = l1
        list1 = []
        list2 = []
        while first != None:
            if first.val not in list1 and first.val not in list2:
                list1.append(first.val)
            elif first.val in list1:
                list1.remove(first.val)
                list2.append(first.val)
            elif first.val in list2:
                pass
            first = first.next
        for j in list1:
            second = second.next
            second.val = j
        second.next = None
        l1 = l1.next
        return(l1)
            
```
