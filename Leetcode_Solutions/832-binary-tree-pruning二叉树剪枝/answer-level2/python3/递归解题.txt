### 解题思路
此处撰写解题思路
关键就在于要想清楚设置为None之后就不存在属性了，所以就从最下边那一层开始设置
### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pruneTree(self, root: TreeNode) -> TreeNode:
        if not root:
            return      

        root.left = self.pruneTree(root.left)
        root.right = self.pruneTree(root.right)
        if self.is_zero(root):
            root = None
        return root

    def is_zero(self, s: TreeNode) -> TreeNode:
        if not s:
            return True
        if s.val == 0:
            return self.is_zero(s.left) and self.is_zero(s.right)
        return False

```