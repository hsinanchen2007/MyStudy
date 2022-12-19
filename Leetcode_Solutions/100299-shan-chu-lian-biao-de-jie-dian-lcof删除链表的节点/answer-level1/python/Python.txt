### 解题思路
简单的判断

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteNode(self, head: ListNode, val: int) -> ListNode:
        t = head
        if head.val == val:
            head = head.next
            return head
        try:
            while t.next is not None:
                if t.next.val == val:
                    t.next = t.next.next
                t = t.next
        except AttributeError as e:
            pass
        return head

```