```
class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        nodes = set()
        while headA:
            nodes.add(headA)
            headA = headA.next
            
        while headB:
            if headB in nodes:
                return headB
            
            headB = headB.next
            
        return None
```