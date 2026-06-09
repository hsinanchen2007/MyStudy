### 解题思路
把见过的节点丢集合里，下次再遇见就是环的开始。

### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def detectCycle(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """

        s = {None}
        while head not in s:
            s.add(head)
            head = head.next
        return head


```