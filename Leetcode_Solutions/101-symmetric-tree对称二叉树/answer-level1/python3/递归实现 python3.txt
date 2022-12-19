执行用时 :52 ms, 在所有 Python3 提交中击败了86.80%的用户
内存消耗 :13.1 MB, 在所有 Python3 提交中击败了74.54%的用户

```python [3]
class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        return self.Symmetric(root, root)
 
    def Symmetric(self, root1, root2):
        if root1 is None and root2 is None:
            return True
        if root1 is None or root2 is None:
            return False
        if root1.val != root2.val:
            return False
        return self.Symmetric(root1.left, root2.right) and self.Symmetric(root1.right,root2.left)
```
