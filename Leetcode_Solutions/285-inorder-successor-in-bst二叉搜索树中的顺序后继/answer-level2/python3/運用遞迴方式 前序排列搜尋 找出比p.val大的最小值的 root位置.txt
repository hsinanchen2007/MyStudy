### 解题思路
運用遞迴方式 前序排列搜尋 找出比p.val大的最小值的 root位置

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def inorderSuccessor(self, root: 'TreeNode', p: 'TreeNode') -> 'TreeNode':
        roots, diff = None, float('inf')
        def search(root):
            nonlocal roots, diff
            if not root:
                return    
            if root.val > p.val and root.val - p.val < diff:
                diff, roots = root.val - p.val, root
            search(root.left)
            search(root.right)
        search(root)
        return roots





```