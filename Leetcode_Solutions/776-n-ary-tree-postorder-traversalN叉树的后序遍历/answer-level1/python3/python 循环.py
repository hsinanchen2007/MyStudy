### 解题思路
父节点先出栈，然后子节点从右到左出栈，返回res倒序

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
            return []
        stack=[root]
        res=[]
        while stack:
            node=stack.pop()
            res.append(node.val)
            for child in node.children:
                stack.append(child)
        return res[::-1]

递归

        # res=[]
        # def postorder(root):
        #     if not root:
        #         return
        #     for i in root.children:
        #         postorder(i)
        #     res.append(root.val)
        # postorder(root)
        # return res
```