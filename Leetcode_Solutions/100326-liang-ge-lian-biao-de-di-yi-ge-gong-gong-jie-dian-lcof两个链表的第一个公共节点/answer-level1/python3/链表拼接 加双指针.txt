1. 注意两个指针要一起出发同样的长度，不能让A，B直接走到最后，再从头开始，会导致步调不一致
2. 注意跳出循环的条件，
3. 不能改变原有的结构，创建新的节点
```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        nheadA = headA
        nheadB = headB

        while nheadA != nheadB:
            if nheadA: #注意判断条件，如果这里是headA.next的话，nheadA一直不为空，当两个链没有交点时，程序会走进无限循环；这里就是为了让nheadA与nheadB同时为空时跳出循环
                nheadA = nheadA.next
            else:
                nheadA = headB
            
            if nheadB:
                nheadB = nheadB.next
            else:
                nheadB = headA
            # nheadA = nheadA.next if nheadA else headB
            # nheadB = nheadB.next if nheadB else headA
        return nheadB
```
