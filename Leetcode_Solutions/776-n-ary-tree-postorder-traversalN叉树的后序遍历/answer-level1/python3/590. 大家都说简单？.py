### 解题思路
我写递归就是玄学

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
    def __init__(self):
        self.post = []
    def postorder(self, root: 'Node') -> List[int]:
        if not root:
            return None     

        for child in root.children:

            self.postorder(child)
            
        self.post.append(root.val)

        return self.post
```