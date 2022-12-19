### 解题思路
rt

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        a = head
        b = head
        while b.next and b.next.next:
            b = b.next.next
            a = a.next
        if not b.next:
            return a
        else:
            return a.next
        

```