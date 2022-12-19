### 解题思路
逐层遍历，先右后左，最后剩下底层最左

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findBottomLeftValue(self, root: TreeNode) -> int:
        next_level = [root]
        while next_level:
            node = next_level.pop(0)
            if node.right: next_level.append(node.right)
            if node.left: next_level.append(node.left)
        return node.val

```