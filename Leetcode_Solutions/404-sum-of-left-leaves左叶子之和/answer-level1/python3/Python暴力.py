### 解题思路
嵌套子函数中不加nonlocal居然能报错

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sumOfLeftLeaves(self, root: TreeNode) -> int:
        s = 0
        def order(root):
            nonlocal s
            if root:
                if root.left and not root.left.left and not root.left.right:
                    s += root.left.val
                order(root.left)
                order(root.right)
        order(root)
        return s
```