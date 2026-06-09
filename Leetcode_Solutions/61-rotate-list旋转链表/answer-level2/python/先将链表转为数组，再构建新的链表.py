判断边界条件有点恶心 =。=
```
class Solution(object):
    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        tmp = []
        iHead = head
        while head:
            tmp.append(head.val)
            head = head.next
        n = len(tmp)
        if k == 0 or n==0:
            return iHead
        if k > n:
            k = k%n
        if k < n:
            tmp = tmp[n-k:n] + tmp[:n-k]
        newHead = tmpHead = ListNode(0)
        for i in range(0,n):
            tmpHead.next = ListNode(tmp[i])
            tmpHead = tmpHead.next
        return newHead.next
            
        
```
