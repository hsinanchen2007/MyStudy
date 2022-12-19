以下运用了迭代，一个一个node找下去，把新的连接之前的，最后返回最后一个node作为head
```
class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        prev = None
        curr = head
        while curr:
            curr.next = prev
            prev = curr
            curr = nextnode
        return prev
```
