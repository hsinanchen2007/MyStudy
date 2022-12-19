### 解题思路
DFS遍历二叉树获得字符串数组，再转换为整数数组并最终求和。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sumNumbers(self, root: TreeNode) -> int:
        if not root:
            return 0
        stack = [(root, '')]
        res = []
        while stack:
            node, char = stack.pop()
            if not node.right and not node.left:
                res.append(char + str(node.val))
            if node.right:
                stack.append((node.right, char + str(node.val)))
            if node.left:
                stack.append((node.left, char + str(node.val)))
        return  sum([int(ch) for ch in res])
```