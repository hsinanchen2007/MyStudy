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
    def findTilt(self, root: TreeNode) -> int:
        self.ans = 0
        def f(node):
            if not node:
                return 0
            left = f(node.left)
            right = f(node.right)
            self.ans += abs(left-right)
            return left+right+node.val
        f(root)

        return self.ans
```