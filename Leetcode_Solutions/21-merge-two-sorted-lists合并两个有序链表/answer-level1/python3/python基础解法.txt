### 解题思路
递归解决，边界条件就是判断l1.val和l2.val大小，然后重复将l1.next,l2.next插入到列表中。

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        if l1 is None:
            return l2
        elif l2 is None:
            return l1
        elif l1.val < l2.val:
            l1.next = self.mergeTwoLists(l1.next, l2)
            return l1
        elif l1.val >= l2.val:
            l2.next = self.mergeTwoLists(l1, l2.next)
            return l2
        
```