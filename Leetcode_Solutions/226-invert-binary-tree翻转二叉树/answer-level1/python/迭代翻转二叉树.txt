### 解题思路
迭代翻转二叉树

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        if root is None:
            return root
        queue = [root]
        while queue:
            top = queue.pop(0)
            temp = TreeNode(-1)
            temp = top.left
            top.left, top.right = top.right, temp
            if top.left:
                queue.append(top.left)
            if top.right:
                queue.append(top.right)
        return root
            
```