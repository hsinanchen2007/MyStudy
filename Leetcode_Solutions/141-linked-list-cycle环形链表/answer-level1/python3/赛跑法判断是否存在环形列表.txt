利用赛跑法，快的总能套圈慢的
``` Python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        if head == None:
            return False
        if head.next == None:
            return False
        slow = head
        fast = head.next
        while slow != None and fast != None:
            if fast.next == slow:
                return True
            slow = slow.next
            if fast.next != None:
                fast = fast.next.next
            else:
                return False
        return False
```
