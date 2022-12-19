```
class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        ha,hb = headA,headB
        while ha!=hb:
            ha = ha.next if ha else headB
            hb = hb.next if hb else headA
        return ha
```
