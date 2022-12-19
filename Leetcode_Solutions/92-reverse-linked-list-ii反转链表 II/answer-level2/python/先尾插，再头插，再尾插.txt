```
class Solution:
    def reverseBetween(self, head, m, n):
        """
        :type head: ListNode
        :type m: int
        :type n: int
        :rtype: ListNode
        """
        newhead = ListNode(0)
        cur, num = newhead, 1
        while num < m:
            cur.next = head
            head = head.next
            cur = cur.next
            cur.next = None
            num += 1
        while num <= n:
            p = head
            head = head.next
            p.next = cur.next
            cur.next = p
            num += 1
        while cur.next:
            cur = cur.next
        cur.next = head
        return newhead.next
```
