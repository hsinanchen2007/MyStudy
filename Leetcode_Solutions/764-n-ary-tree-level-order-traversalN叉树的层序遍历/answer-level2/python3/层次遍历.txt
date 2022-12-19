```python
from typing import List
from collections import deque

# Definition for a Node.
class Node:
    def __init__(self, val, children):
        self.val = val
        self.children = children


class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        res = []
        dq = deque([root])
        level = 0
        while dq:
            res.append([])
            length = len(dq)
            for _ in range(length):
                cur = dq.popleft()
                res[level].append(cur.val)
                dq.extend(cur.children)
            level += 1
        return res
```