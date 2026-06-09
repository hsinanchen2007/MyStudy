### 解题思路
递归

### 代码

```python3
"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""
class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        if not root:
            return []
        else:
            res = []
            queue = [root]
            while queue:
                size = len(queue)
                temp = []
                for i in range(size):
                    r = queue.pop(0)
                    temp.append(r.val)
                    if r.children:
                        for x in r.children:
                            queue.append(x)
                res.append(temp)
            return res










```