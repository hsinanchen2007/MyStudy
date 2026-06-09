### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def leafSimilar(self, root1, root2):
        def dfs(root):
            stack = [root]
            ans = []
            while stack:
                root = stack.pop()
                if root:
                    children = [root.left,root.right]
                    if not any(children):
                        ans += [root.val]
                    else:
                        stack.append(root.right)
                        stack.append(root.left)
            return ans
        return dfs(root1) == dfs(root2)
```