### 解题思路
找到每一次停止的条件，即指针的next为null的情况。

### 代码

```python
# Definition for singly-linked list.
class ListNode(object):
     def __init__(self, x):
         self.val = x
         self.next = None

class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head is None:
            return None
        if head.next is None:
            return head
        p = head
        q = head
        while head.next:
            head = head.next
        while q.next != head:
            q = q.next
        q.next = head.next
        head.next = self.reverseList(p)
        return head
```