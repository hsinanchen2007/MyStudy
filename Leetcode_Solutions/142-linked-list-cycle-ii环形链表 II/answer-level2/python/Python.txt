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
    def detectCycle(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        visit=set()
        node=head
        while node!=None:
            if node not in visit:
                visit.add(node)
                node=node.next
            else:
                return node
        return None
```