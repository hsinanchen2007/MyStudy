### 解题思路
时间复杂度：O（n2）
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
    def isBalanced(self, root: TreeNode) -> bool:
        if not root:
            return True
        if not root.left and not root.right:
            return True
        if root.left and not root.right:
            if root.left.left or root.left.right:
                return False
        if root.right and not root.left:
            if root.right.left or root.right.right:
                return False
        if root.left and root.right:
            if abs(self.get_tree_height(root.left) - self.get_tree_height(root.right)) > 1:
                return False
        return self.isBalanced(root.left) and self.isBalanced(root.right)
        
    def get_tree_height(self, root: TreeNode) -> int:
        if not root:
            return 0
        if not root.left and not root.right:
            return 1
        return max(self.get_tree_height(root.left), self.get_tree_height(root.right)) + 1

```