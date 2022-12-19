### 解题思路
写一个is_sym函数, 输入两个节点.

判断两个节点是否本身值相等, 左子==右子, 右子==左子, 都满足就是对称的!

本质上还是一个递归解法.

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        def is_sym(left, right):
            if left is None and right is None:
                return True
            if left is None or right is None:
                return False
            return left.val == right.val and is_sym(left.left, right.right) and is_sym(left.right, right.left)
        
        if root is None:
            return True
        return is_sym(root.left, root.right)
        
        
```