```
class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        l = headA
        r = headB
        while l != r:
            l = l.next if l else headB
            r = r.next if r else headA
        return l
```
