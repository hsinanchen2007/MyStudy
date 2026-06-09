### 解题思路
迭代法N叉树后序遍历

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
        if root is None:
            return root
        stack1, stack2, result = [], [], []
        stack1.append(root)
        while stack1:
            node = stack1.pop()
            stack2.append(node)
            if node.children:
                stack1.extend(node.children)
        while stack2:
            top = stack2.pop()
            result.append(top.val)
        return result
```