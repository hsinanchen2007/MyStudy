
```
class Solution(object):
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head:
            return head
        newHead = head
        ret = []
        tmp = []
        while head:
            ret.append(head.val)
            head = head.next
        for item in ret:
            if ret.count(item) < 2:
                tmp.append(item)
        newHead = pHead = ListNode(0)
        for item in tmp:
            newHead.next = ListNode(item)
            newHead = newHead.next
        return pHead.next
```
