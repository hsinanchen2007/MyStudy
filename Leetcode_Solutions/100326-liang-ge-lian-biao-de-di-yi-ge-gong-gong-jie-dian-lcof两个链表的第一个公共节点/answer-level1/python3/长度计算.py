```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        h1, h2 = headA, headB 
        size1 , size2 = 0, 0
        while h1:
            size1+=1
            h1 = h1.next 
        while h2:
            size2 += 1
            h2 = h2.next 
        if size1==0 or size2 ==0: return None
        while size1 > size2:
            size1 -= 1
            headA = headA.next 
        while size2> size1:
            size2 -= 1
            headB = headB.next 
        pre = None
        while headA != headB:
            headA = headA.next 
            headB = headB.next
        return headA
```
