```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        if head == None:
            return(head)
        l1 = ListNode(0)
        l1.next = head
        list1 = []
        first = l1.next
        second = l1.next
        while first != None:
            list1.append(first.val)
            first = first.next
        len1 = len(list1)
        k = k % len1
        list2 = list1[:-k]
        n1 = len1 - k
        list3 = list1[n1:]
        list3.extend(list2)
        #return(list3)
        for i in list3:
            second.val = i
            second = second.next
        l1 = l1.next
        return(l1)
```
