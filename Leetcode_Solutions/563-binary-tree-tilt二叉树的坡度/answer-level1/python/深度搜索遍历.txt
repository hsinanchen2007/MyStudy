### 解题思路
一开始没有看清是左右子树之和，结果错了还很纳闷哪里出了问题。后来加上了dfs部分。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findTilt(self, root: TreeNode) -> int:
        if root is None:
            return 0

        def func(root):
            if root.left is None and root.right is None:
                return root.val
            elif root.left and root.right is None:
                return root.val + func(root.left)
            elif root.right and root.left is None:
                return root.val + func(root.right)
            else:
                return root.val + func(root.left) + func(root.right)

        sum_ = 0
        queue = [root]
        while queue:
            temp = queue.pop()
            if temp.left and temp.right:
                sum_ = sum_ + abs(func(temp.left) - func(temp.right))
                queue.append(temp.left)
                queue.append(temp.right)
            elif temp.left:
                sum_ = sum_ + abs(func(temp.left))
                queue.append(temp.left)
            elif temp.right:
                sum_ = sum_ + abs(func(temp.right))
                queue.append(temp.right)

        return sum_
```