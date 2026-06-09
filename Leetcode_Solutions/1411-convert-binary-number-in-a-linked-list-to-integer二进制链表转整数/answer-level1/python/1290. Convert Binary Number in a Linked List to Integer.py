### 解题思路
1. head是否为空 return 0
2. 遍历所有值

### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def getDecimalValue(self, head):
        """
        :type head: ListNode
        :rtype: int
        """
        if head is None:
            return 0
        
        string, cur = '', head
        while cur is not None:
            string += str(cur.val)
            cur = cur.next

        return int(string, 2)
```