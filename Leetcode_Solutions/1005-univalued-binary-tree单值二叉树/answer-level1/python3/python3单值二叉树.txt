### 解题思路
递归判断子树的根节点是否与当前根节点值一致，若一致，则继续往下判断，否则输出FALSE。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isUnivalTree(self, root: TreeNode) -> bool:
        if root.left and root.right:
            if root.left.val==root.val and root.right.val==root.val:
                return self.isUnivalTree(root.left) and self.isUnivalTree(root.right)
            else:
                return False
        elif root.left:
            if root.left.val==root.val:
                return self.isUnivalTree(root.left)
            else:
                return False
        elif root.right:
            if root.right.val==root.val:
                return self.isUnivalTree(root.right)
            else:
                return False
        else:
            return True
```

![image.png](https://pic.leetcode-cn.com/f2df4f883097b7a3210a1ddf8a1a47f79bdcc7d5c7553ded38940a4c9d2861a5-image.png)
