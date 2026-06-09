### 解题思路
此处撰写解题思路

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        return 0 if(root == None) else (max(self.maxDepth(root.left), self.maxDepth(root.right)) + 1)
    def isBalanced(self, root: TreeNode) -> bool:
        return True if(root == None) else ((self.isBalanced(root.left) and self.isBalanced(root.right)) if(abs(self.maxDepth(root.left) - 
        self.maxDepth(root.right)) <= 1) else False)
```