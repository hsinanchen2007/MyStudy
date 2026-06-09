```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        first = ListNode(0)
        result = first
        current = head
        while current:
            runner = current.next
            if runner is None or current.val != runner.val:
                first.next = current
                first = current
                first.next = None
                current = runner
            else:
                while runner and current.val == runner.val:
                    runner = runner.next
                current.next = runner
                current = runner
        return result.next
```
