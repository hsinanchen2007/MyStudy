使用两个指针来实现链表反转。一个指针指向已反转链表的头节点，一个指针指向待反转链表的头节点。
```
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        ret = None
        while head:
            nhead = head.next
            head.next = ret
            ret = head
            head = nhead
        return ret
```
