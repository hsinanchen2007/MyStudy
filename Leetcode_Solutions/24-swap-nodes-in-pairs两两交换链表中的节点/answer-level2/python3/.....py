```python
# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        dummy, node = ListNode(-1), head
        pre = dummy
        while node and node.next:
            tmp = node.next.next
            pre.next = node.next
            node.next.next = node
            node, pre = tmp, node
        pre.next = node
        return dummy.next

    def swapPairs1(self, head: ListNode) -> ListNode:
        def recur(head: ListNode) -> ListNode:
            if not head or not head.next:
                return head
            tail = recur(head.next.next)
            res = head.next
            head.next.next = head
            head.next = tail
            return res
        return recur(head)
```