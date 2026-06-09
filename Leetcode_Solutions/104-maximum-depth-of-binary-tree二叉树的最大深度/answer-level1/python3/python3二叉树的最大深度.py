### 解题思路
分别对左子树右子树递归调用函数，并将子树的最大深度加一。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if root==None:
            return 0
        return max(self.maxDepth(root.left)+1, self.maxDepth(root.right)+1)
```

![image.png](https://pic.leetcode-cn.com/a7beaac26312fe948dd687d52fb02c674879ac2a88637cfc7812d71ca3373579-image.png)
