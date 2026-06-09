### 解题思路
递归中序遍历

### 代码

```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def kthLargest(self, root: TreeNode, k: int) -> int:
        p = lambda n: p(n.left) + [n.val] + p(n.right) if n else []
        return p(root)[-k]
```