### 解题思路
设置三个指针p, q, r代表三个连续的节点，令q指向p，r的作用是记录下一次迭代位置。

### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head is None or head.next is None:
            return head
        p = head
        q = p.next
        r = q.next
        head.next = None
        while r:
            q.next = p
            p = q
            q = r
            r = r.next
        q.next = p
        return q            
```