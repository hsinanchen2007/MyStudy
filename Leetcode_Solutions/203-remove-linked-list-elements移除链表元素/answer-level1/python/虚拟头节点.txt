# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def removeElements(self, head, val):
        """
        :type head: ListNode
        :type val: int
        :rtype: ListNode
        """
        if head == None :
            return None
        newlist = ListNode(0)
        newlist.next = head
        p = newlist
        while p.next:
            if p.next.val == val:
                p.next = p.next.next
            else:
                p = p.next
        return newlist.next
        