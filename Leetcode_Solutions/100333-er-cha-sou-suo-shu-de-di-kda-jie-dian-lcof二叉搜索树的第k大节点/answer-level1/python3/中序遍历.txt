
```python []
class Solution:
    def kthLargest(self, root: TreeNode, k: int) -> int:
        tmp = []
        def helper(root):
            if root.left:
                helper(root.left)
            tmp.append(root.val)
            if root.right:
                helper(root.right)

        helper(root)
        return tmp[-k]
```