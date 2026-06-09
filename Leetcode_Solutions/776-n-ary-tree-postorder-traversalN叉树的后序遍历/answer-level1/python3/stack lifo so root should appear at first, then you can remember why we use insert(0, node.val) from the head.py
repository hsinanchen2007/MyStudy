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
    def postorder(self, root: 'Node') -> List[int]:

        if not root:
            return root

        stack = [root]
        res = []
        while stack:

            node = stack.pop()
            # stack lifo so root should appear at first, then you can remember why 
            # we use insert(0, node.val) from the head
            res.insert(0,node.val)
            for i in node.children:
                stack.append(i)

        return res
```