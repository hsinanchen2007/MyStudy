### 解题思路
此处撰写解题思路

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
    """给定一个树，返回最大深度
    """
    def maxDepth(self, root: 'Node') -> int:
        """递归，DFS
        1.基本结束条件：
        2.减小规模，向基本结束条件演进
        3.调用自身
        """
        if not root: return 0

        result = []
        for child in root.children:
            result.append(self.maxDepth(child))
        if not result:
            return 1
        return max(result) + 1

        

```