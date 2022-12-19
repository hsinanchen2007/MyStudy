### 解题思路
递归的返回max(左子数，右子树)+1的值就可以

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
        res=0
        def helper(root):
            if not root:
                return 0
            return max(helper(root.left),helper(root.right))+1
        return helper(root)
```