### 解题思路
构建另一个函数，分别判断左子树和右子树，如果都为None，那么就是True，如果存在，判断当前左右节点的值是否相等并递归下去。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def Symmetric(self,t1,t2):
        if t1 == None and t2 == None:
            return True
        elif t1 and t2:
            return t1.val == t2.val and self.Symmetric(t1.left,t2.right) and self.Symmetric(t1.right,t2.left)
        else:
            return False

    def isSymmetric(self, root: TreeNode) -> bool:
        if root == None:
            return True
        return self.Symmetric(root.left,root.right)

```