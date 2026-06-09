```python
class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        return self.balanced(root)[0]
    
    def balanced(self, root):
        """返回值是当前树是否平衡及其树高"""
        if not root:
            return True, 0
        
        l_balanced, lh = self.balanced(root.left)
        r_balanced, rh = self.balanced(root.right)

        if l_balanced and r_balanced and abs(lh - rh) <= 1:
            return True, max(lh, rh) + 1
        else:
            return False, max(lh, rh) + 1
```