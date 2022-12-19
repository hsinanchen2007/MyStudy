
### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:

        self.ans = 1
        def helper(node):
            
            if not node: return 0
            
            L = helper(node.left)
            R = helper(node.right)
            
            self.ans = max(self.ans, L+R+1)
            
            return max(L, R) + 1

        helper(root)
        return self.ans - 1


```