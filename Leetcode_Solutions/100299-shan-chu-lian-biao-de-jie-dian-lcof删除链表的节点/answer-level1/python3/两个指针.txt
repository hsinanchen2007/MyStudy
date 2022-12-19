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
    def deleteNode(self, head: ListNode, val: int) -> ListNode:
        p = ListNode(-1)
        p.next = head
        q = p
        while p.next:
            if p.next.val == val:
                p.next = p.next.next
            else:
                p = p.next
        return q.next

```