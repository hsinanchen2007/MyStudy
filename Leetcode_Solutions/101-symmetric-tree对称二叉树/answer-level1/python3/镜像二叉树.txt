### 解题思路
由于是镜像二叉树，所以左子树从左往右遍历，右子树从右往左遍历，比较对应的值。

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
        def equal(l, r):
            global flag
            if l == None and r == None:
                return
            if l == None and r != None:
                flag = False
                return
            if l != None and r == None:
                flag = False
                return
            if l.val != r.val:
                flag = False
                return
            equal(l.left, r.right)
            equal(l.right, r.left)
        global flag
        flag = True
        equal(root.left, root.right)
        return flag
```