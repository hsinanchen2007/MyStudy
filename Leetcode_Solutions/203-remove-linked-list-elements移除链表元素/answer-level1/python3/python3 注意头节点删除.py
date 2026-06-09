```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeElements(self, head: ListNode, val: int) -> ListNode:
        if head == None:
            return head
        p = head
        q = head.next
        while p.val == val :
            head = q
            p = p.next
            if q == None:
                break
            q = q.next
        while q !=  None :
            if q.val == val:
                p.next = q.next
                q = q.next
                continue
            p = q
            q = q.next
        return head
            




```
