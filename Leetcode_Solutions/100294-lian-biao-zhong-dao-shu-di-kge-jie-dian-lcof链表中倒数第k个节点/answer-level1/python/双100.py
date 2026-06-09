```
class Solution(object):
    def getKthFromEnd(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if not head:
            return 
        a = 0
        phead = head
        phead1 = head
        while phead != None:
            a += 1
            phead = phead.next
        for i in range(1,a-k+1):
            phead1 = phead1.next
        return phead1
```
