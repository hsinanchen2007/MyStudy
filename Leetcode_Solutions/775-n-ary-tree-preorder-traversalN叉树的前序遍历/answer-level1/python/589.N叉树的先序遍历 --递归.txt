### 解题思路
和二叉树类似，N叉树先序是先自身，再从左到右遍历各孩子，依然可以使用辅助函数。

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
    def preorder(self, root: 'Node') -> List[int]:
        L=[]
        def pres(root):
            if not root:return
            L.append(root.val)#先自身
            for node in root.children:#再从左到右的各孩子
                pres(node)
        pres(root)
        return L
```