```
class Solution(object):
    def reverseList(self, head):
        pre = None
        cur = head
        while cur != None:
            lat = cur.next
            cur.next = pre
            pre = cur 
            cur = lat

        return pre

    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        if head != None and head.next != None\
                and self.reverseList(head) == head:
            return True
        return False
```