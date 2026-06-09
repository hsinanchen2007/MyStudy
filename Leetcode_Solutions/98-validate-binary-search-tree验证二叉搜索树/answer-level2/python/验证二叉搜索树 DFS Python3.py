### 解题思路
唉。。脑子有点儿大
helper(root.left, lower, root.val) and helper(root.right, root.val, upper)
不能写成helper(root.left, root.val) and helper(root.right, root.val)

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:

    def isValidBST(self, node: TreeNode) -> bool:

        def helper(root, lower=float('-inf'), upper=float('inf')):
            if not root:
                return True
            if not  lower < root.val < upper:
                return False
            return helper(root.left, lower, root.val) and helper(root.right, root.val, upper)

        return helper(node)


```