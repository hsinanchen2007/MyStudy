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
        _, h = self._reverseList(head)
        return h

    def _reverseList(self, head : ListNode) ->(ListNode, ListNode):
        if head == None:
            return None, None
        elif head.next == None:
            return head, head
        else:
            p, h = self._reverseList(head.next)
            p.next = head
            head.next = None
            return head, h
```