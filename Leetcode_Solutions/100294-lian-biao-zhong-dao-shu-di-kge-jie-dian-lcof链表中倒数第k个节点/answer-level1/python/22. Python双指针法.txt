### 解题思路
这道题理应考虑到k > 节点数量的情况。

### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def getKthFromEnd(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if head is None:
            return None
        p = q = head
        for _ in range(k - 1):
            if q is None:
                return head
            q = q.next
        while q.next:
            p = p.next
            q = q.next
        return p
```