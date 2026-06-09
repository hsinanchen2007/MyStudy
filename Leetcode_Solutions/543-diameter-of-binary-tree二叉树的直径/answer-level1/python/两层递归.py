### 解题思路
两层递归

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
        if not root:
            return 0

        return max(self.depth(root.left)+self.depth(root.right),
                    self.diameterOfBinaryTree(root.left),
                    self.diameterOfBinaryTree(root.right))



    def depth(self,root):
        if not root:
            return 0
        return 1 + max(self.depth(root.left), self.depth(root.right))

        
```