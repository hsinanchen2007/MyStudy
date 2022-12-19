### 解题思路
递归，查找子接电中最大的

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
    def maxDepth(self, root: 'Node') -> int:
        if root:
            if root.children:
                return max([self.maxDepth(node) for node in root.children]) + 1
            else:
                return 1
        else:
            return 0
```