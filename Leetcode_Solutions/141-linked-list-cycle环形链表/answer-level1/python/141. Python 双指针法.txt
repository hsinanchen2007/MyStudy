### 解题思路
如果链表存在环，那么假如有两个速度分别为1和2的指针一起移动，那么肯定会在未来的某一刻相遇。可以想象成两个人在操场跑步，一个速度快一个速度慢，速度快的总会追上速度慢的。

### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        p = q = head
        while q and q.next:
            q = q.next.next
            p = p.next
            if p == q:
                return True
        return False
```