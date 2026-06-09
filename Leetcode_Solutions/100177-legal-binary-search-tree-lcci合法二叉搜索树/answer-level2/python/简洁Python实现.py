### 代码

```python3
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        return self.valid(root, float('-inf'), float('inf'))
    
    def valid(self, root, mi, ma):
        if not root:
            return True
        if root.val >= ma or root.val <= mi:
            return False
        return self.valid(root.left, mi, root.val) and self.valid(root.right, root.val, ma)
```