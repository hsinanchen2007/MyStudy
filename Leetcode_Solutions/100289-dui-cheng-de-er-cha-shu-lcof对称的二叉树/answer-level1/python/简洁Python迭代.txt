### 代码

```python3
class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        def Symmetric(p1, p2):
            if p1 and p2:
                return p1.val == p2.val and Symmetric(p1.left, p2.right) and Symmetric(p1.right, p2.left)
            else:
                return p1 is p2
        if not root:
            return True
        return Symmetric(root.left, root.right)
```