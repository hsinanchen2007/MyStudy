```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:

        stack1 = []
        stack2 = []

        while headA:
            stack1.append(headA)
            headA = headA.next
        
        while headB:
            stack2.append(headB)
            headB = headB.next
        res = None
        while stack1 and stack2:
            nodea = stack1.pop()
            nodeb = stack2.pop()

            if nodea == nodeb:
                res = nodea
                if not stack1 or not stack2:
                    return res

            if nodea != nodeb:
                return res

        return 
                
```
