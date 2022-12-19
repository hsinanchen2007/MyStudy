### 解题思路
利用dictionary, 每次将完整的节点放入。

### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def hasCycle(self, head):
        if head is None:
            return False
        cur = head
        _dict = {}
        while cur is not None:
            if cur in _dict:
                return True
            _dict[cur] = 1
            cur = cur.next
        return False
```