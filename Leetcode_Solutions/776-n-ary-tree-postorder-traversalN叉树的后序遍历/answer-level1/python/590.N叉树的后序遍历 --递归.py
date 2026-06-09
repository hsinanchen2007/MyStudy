### 解题思路
N叉树的后序遍历和二叉树的后序遍历类似，先遍历孩子，再自身。

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
    def postorder(self, root: 'Node') -> List[int]:
        L=[]
        def posr(root):
            if not root:return 
            for node in root.children:
                posr(node)
            L.append(root.val)
        posr(root)
        return L
```