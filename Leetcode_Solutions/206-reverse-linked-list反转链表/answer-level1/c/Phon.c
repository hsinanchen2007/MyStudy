### 解题思路
此处撰写解题思路

### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseList(self, head):
        if head == None or head.next == None:
            return head
        newHead=ListNode(2)
        next = head.next
        newHead = self.reverseList(next)
        next.next = head
        head.next = None
        return newHead
```