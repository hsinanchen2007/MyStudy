### 解题思路
此处撰写解题思路

### 代码

```python
"""
# Definition for a Node.
class Node(object):
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""
class Solution(object):
    def maxDepth(self, root):
        """
        :type root: Node
        :rtype: int
        """
        if not root:
            return 0
        stack=[root]
        dep=0
        while stack:
            tmp=[]
            for i in range(len(stack)):
                for chi in stack[i].children:
                    tmp.append(chi)
            dep+=1
            stack=tmp
        return dep
```