### 解题思路
时间复杂度：O（n）
空间复杂度：O（n）

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    
    def hasPathSum(self, root: TreeNode, sum0: int) -> bool:
        
        if not root:
            return False
        if root.val == sum0 and (not root.left and not root.right):
            return True
        return self.hasPathSum(root.left, sum0-root.val) or \
        self.hasPathSum(root.right, sum0-root.val)
```