### 解题思路

解题思路抄题解的，主要是想展示一下 Python 的排版功能而已。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lcaDeepestLeaves(self, root: TreeNode) -> TreeNode:
        def recursion(node):
            if node is None:
                return 0, None
            l, r = recursion(node.left), recursion(node.right)
            return max(l[0], r[0]) + 1, \
                node if l[0] == r[0] else \
                l[1] if l[0] >  r[0] else \
                r[1]
        return recursion(root)[1]
```