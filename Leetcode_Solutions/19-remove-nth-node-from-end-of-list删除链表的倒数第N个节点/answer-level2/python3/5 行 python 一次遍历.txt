```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        l = []
        while head: l, head = l + [head], head.next
        if n != len(l): l[-n-1].next = l[-n].next
        del l[-n]
        return l and l[0]
```
- 列表记录整个链表，换成队列记录最后几个可以把空间复杂度压到 O(1)