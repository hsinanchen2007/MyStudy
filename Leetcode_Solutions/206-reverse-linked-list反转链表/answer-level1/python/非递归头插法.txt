基本思路每次取出头节点指向新的链表的头部，形成逆置

```
class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        h = None
        while head:
            h1 =head.next
            head.next = h
            h = head
            head = h1
        return h
```
