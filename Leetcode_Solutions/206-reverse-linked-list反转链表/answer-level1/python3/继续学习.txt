### 解题思路
普通迭代，后期继续优化
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
        p = head
        rev = None
        t = None
        while p:
            t = p.next
            p.next = rev
            rev = p
            p = t
        return rev






```