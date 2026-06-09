## 思路

直接递归，交换左右节点

## 代码

```python3

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def mirrorTree(self, root: TreeNode) -> TreeNode:
        if not root:
            return
        root.left, root.right = root.right, root.left
        self.mirrorTree(root.left)
        self.mirrorTree(root.right)
        return root
```



## 结果

![image.png](https://pic.leetcode-cn.com/fbf78430bc809f149f507dd1ef89752fa59a3e9e1b6a727363e7c66b0eabad1a-image.png)

