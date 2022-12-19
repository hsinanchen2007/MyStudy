### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        dummy = l0 = ListNode(0)
        while l1 and l2:
            if l1.val > l2.val:
                l1, l2 = l2, l1
            l0.next = l1
            l0 = l0.next
            l1 = l1.next
        if l2:
            l1 = l2
        l0.next = l1
        return dummy.next
                
```