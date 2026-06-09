### 解题思路
递归，速度98.78%，我写的循环最快56%吧

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        if not l1:
            return l2
        if not l2:
            return l1
        if l1.val <= l2.val:
            p = l1
            p.next = self.mergeTwoLists(l1.next, l2)
        else:
            p = l2
            p.next = self.mergeTwoLists(l1, l2.next)
        return p
                
        
```