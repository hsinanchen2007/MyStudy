### 解题思路


### code
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        last = None
        now = head
        while now:
            (now.next, last, now) = (last, now, now.next)
        return last