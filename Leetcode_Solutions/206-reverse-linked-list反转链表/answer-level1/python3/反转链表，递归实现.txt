### 解题思路
此处撰写解题思路

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if not head:
            return None
        res = None
        def reverse(node):
            nonlocal res
            if not node.next:
                res = node
                return
            reverse(node.next)
            node.next.next = node
            node.next = None
        reverse(head)
        return res
```