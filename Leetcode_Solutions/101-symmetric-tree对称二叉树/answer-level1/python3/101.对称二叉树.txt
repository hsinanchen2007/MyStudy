### 解题思路
@Batman 的评论方法
递归，判断
左子树的右节点 ?= 右子树的左节点
左子树的左节点 ?= 右子树的右节点

![image.png](https://pic.leetcode-cn.com/ee88cb1a3681706352f87b11e28e865a7157942917f19b761f6ad48c89836439-image.png)



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
        if not root:
            return True
        else:
            return self.childTreeIsSymmetric(root.right,root.left)
    
    def childTreeIsSymmetric(self,p,q):
        if not p or not q:
            return p == q
        if p.val != q.val:
            return False
        return self.childTreeIsSymmetric(p.left,q.right) and self.childTreeIsSymmetric(p.right,q.left)
```