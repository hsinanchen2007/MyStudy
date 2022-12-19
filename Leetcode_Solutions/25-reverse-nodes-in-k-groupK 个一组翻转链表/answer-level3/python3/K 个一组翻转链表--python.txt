```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        if head == None or head.next == None or k < 2:
            return head
        new = ListNode(0)
        p1, p2, m = head, head, k
        while p2 != None and m > 0:
            p2 = p2.next
            m -= 1
        if m > 0:
            return head
        while p1 != p2:
            temp = p1.next
            p1.next = new.next
            new.next = p1
            p1 = temp
        head.next = self.reverseKGroup(p2, k)
        return new.next
```
