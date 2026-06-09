```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        l1 = ListNode(0)
        l1.next = head
        first = l1
        second = l1
        while first != None:
            list1 = []
            for i in range(k):
                if first.next != None:
                    list1.append(first.next.val)
                    first = first.next
                else:
                    l1 = l1.next
                    return(l1)
            list1.reverse()
            for j in list1:
                second.next.val = j
                second = second.next
        return(l1)
                
```
