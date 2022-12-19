在DFS的过程中，实时记录下入栈节点的深度即可。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findBottomLeftValue(self, root: TreeNode) -> int:
        obj = (1,root)
        stack = [obj]
        while stack:
            depth,node = stack.pop()
            if depth > obj[0]:
                obj = (depth,node)
            if node.right:
                stack.append((depth+1,node.right))
            if node.left:
                stack.append((depth+1,node.left))
        return obj[1].val
```