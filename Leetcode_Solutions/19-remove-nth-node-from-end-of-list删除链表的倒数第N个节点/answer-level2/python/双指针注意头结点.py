双指针法务必注意删除的是头结点的情况，被头节点卡了好久

```
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        if not head:
            return None
        addNode = ListNode(0)
        addNode.next = head
        cur1 = cur2 = addNode
        count = 0
        while cur1:
            if count <= n:
                count += 1
            else:
                cur2 = cur2.next
            cur1 = cur1.next
        if cur2.next == head:
            return head.next
        else:
            cur2.next = cur2.next.next
            return head
```
