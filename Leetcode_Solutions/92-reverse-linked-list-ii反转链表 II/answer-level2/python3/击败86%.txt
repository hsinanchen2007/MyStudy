```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
        first = head
        second = head
        list1 = []
        while first != None:
            list1.append(first.val)
            first = first.next
        list2 = list1[:m-1]
        list3 = list1[m-1:n]
        list3.reverse()
        list4 = list1[n:]
        list2.extend(list3)
        list2.extend(list4)
        for i in list2:
            second.val = i
            second = second.next
        return(head)
```
