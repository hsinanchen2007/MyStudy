### 解题思路
其实就是递归，每一步只解决当前这一个节点及其左右儿子所组成的小树是否满足反转

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def flipEquiv(self, root1: TreeNode, root2: TreeNode) -> bool:
        if(root1==None and root2==None):
            return 1
        if(not (root1 and root2)):
            return 0
        if not(root1.left or root1.right or root2.left or root2.right):#叶子节点
            if(root1.val==root2.val):
                return 1
#以下是单边子树
        if(root1.left and root2.left and(root1.right==None and root2.right==None)):#左左
            if(root1.left.val==root2.left.val):
                return self.flipEquiv(root1.left,root2.left)
        if (root1.right and root2.right and(root1.left==None and root2.left==None)):  # 右右
            if (root1.right.val == root2.right.val):
                return self.flipEquiv(root1.right, root2.right)
        if(root1.right and root2.left and(root1.left==None and root2.right==None)):#右左
            if(root1.right.val==root2.left.val):
                return self.flipEquiv(root1.right,root2.left)
        if (root1.left and root2.right and (root1.right==None and root2.left==None)):  # 左右
            if (root1.left.val == root2.right.val):
                return self.flipEquiv(root1.left, root2.right)
        if(root1.left and root2.left and root1.right and root2.right):#都有
            return self.flipEquiv(root1.left,root2.left) and self.flipEquiv(root1.right,root2.right) or self.flipEquiv(root1.left,root2.right) and self.flipEquiv(root1.right,root2.left)

```