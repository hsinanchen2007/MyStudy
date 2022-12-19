递归，题目中同一层的兄弟结点存储在list中，使用循环处理同一层的兄弟结点，但优先处理左子树。

```
"""
# Definition for a Node.
class Node(object):
    def __init__(self, val, children):
        self.val = val
        self.children = children
"""
from collections import deque
class Solution(object):
    def postorder(self, root):
        """
        :type root: Node
        :rtype: List[int]
        """
        res = []
       
        def h(root):
            if root is None:
                return
            i = 0
            # 使用循环处理同一层的兄弟结点，但优先处理左子树
            while i < len(root.children):   
                h(root.children[i])
                i += 1
            res.append(root.val)
            
        h(root)
        return res
```




