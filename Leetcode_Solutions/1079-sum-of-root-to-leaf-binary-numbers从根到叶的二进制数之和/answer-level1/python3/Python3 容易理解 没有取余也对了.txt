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
    def sumRootToLeaf(self, root: TreeNode) -> int:
        def _sum(node, res):
            if not node:
                return 0
            elif not node.left and not node.right:
                return res + node.val
            
            res += node.val           
            return _sum(node.left, res << 1) + _sum(node.right, res << 1)

        return _sum(root, 0)
```