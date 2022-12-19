### 解题思路
此处撰写解题思路
1. 需要判断两条：1）是否为完整二叉树 2）树的左节点是否与树的右节点相等
### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        if root == None:
            return True
        def help(left, right):
            
            if left == None and right == None:
                return True
            if left == None or right == None:
                return False
            if left.val != right.val:
                return False
            return help(left.left, right.right) and help(left.right, right.left)
        return help(root, root)
```