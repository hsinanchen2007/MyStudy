### 代码
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:
    def partition(self, head: ListNode, x: int) -> ListNode:
        left,right = ListNode(0),ListNode(0)
        l,r = left,right
        while head :
            if head.val <x: 
                left.next = ListNode(head.val) 
                left = left.next
            else:
                right.next = ListNode(head.val)
                right = right.next
            head = head.next
        left.next = r.next
        return l.next
```