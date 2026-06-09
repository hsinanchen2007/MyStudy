```
class Solution(object):
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        l = ListNode(None)
        ret = l
        l.next  = l1
        while l2:
            if l.next and l.next.val <= l2.val:
                l = l.next
                continue
            l.next, l2 = l2, l.next 
        return ret.next
```
