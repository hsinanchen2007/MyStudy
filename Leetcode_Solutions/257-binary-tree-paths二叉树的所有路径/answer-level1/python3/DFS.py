### 解题思路

DFS

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def binaryTreePaths(self, root: TreeNode) -> List[str]:
        
        def dfs(node):
            if not node.left and not node.right:
                tmp.append(node.val)
                res.append("->".join(map(str, tmp)))
                tmp.pop()
                return
            tmp.append(node.val)
            if node.left:
                dfs(node.left)
            if node.right:
                dfs(node.right)
            tmp.pop()
        if not root:
            return []
        tmp = []
        res = []
        dfs(root)
        return res
            
```