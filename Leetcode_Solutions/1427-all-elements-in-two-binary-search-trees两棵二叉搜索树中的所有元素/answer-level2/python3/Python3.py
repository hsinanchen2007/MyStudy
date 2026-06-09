### 解题思路
dfs

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def getAllElements(self, root1: TreeNode, root2: TreeNode) -> List[int]:
        l = []
        def dfs(root):
            if not root:
                return
            l.append(root.val)
            dfs(root.left)
            dfs(root.right)
        dfs(root1)
        dfs(root2)
        return sorted(l)
```