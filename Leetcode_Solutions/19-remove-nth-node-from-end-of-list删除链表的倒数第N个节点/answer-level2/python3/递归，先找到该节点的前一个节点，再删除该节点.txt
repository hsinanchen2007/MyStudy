```
# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def __init__(self):
        self.last_n = None

    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        self.get_last_n(head, n)

        if self.last_n is None:
            return head.next
        self.last_n.next = self.last_n.next.next

        return head

    def get_last_n(self, head: ListNode, n: int) -> int:
        if head is None:
            return 0

        l = self.get_last_n(head.next, n)

        if l == n:
            self.last_n = head
        return l + 1

```