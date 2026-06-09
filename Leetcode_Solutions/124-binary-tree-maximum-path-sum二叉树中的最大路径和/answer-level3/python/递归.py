### 解题思路
递归

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxPathSum(self, root: TreeNode) -> int:
        def maxend(root):
            if not root:
                return 0
            left = maxend(root.left)
            right = maxend(root.right)
            # 同时加上left和right的值
            self.maximum = max(self.maximum, root.val+left+right)
            # 只能带一边的树，不然的话就成为一个回路了
            return max(root.val + max(left, right), 0)
        self.maximum = float('-inf')
        maxend(root)
        return self.maximum
```