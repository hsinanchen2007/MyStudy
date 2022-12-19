### 解题思路
**思路：**
1.定义一个判断左右子树是否相等的辅助函数checkTwoTree(self, leftTree, rightTree)，依次比较：
· 若左子树和右子树均为空，直接返回True；
· 若左子树为空，右子树非空，说明不对称，返回False；
· 若左子树非空，右子树为空，说明不对称，返回False;
· 若左子树的值和右子树的值不等，也返回False
该比较的都比较完了，然后就可以开始递归了：
     left = self.checkTwoTree(leftTree.left, rightTree.right) 比较左子树的左节点和右子树的右节点
     right = self.checkTwoTree(leftTree.right, rightTree.left) 比较左子树的右节点和右子树的左节点
最后return left and right 即可得到辅助函数的值。

2.回到原函数，首先判断树是否为空，然后直接调用辅助函数，返回调用后的值即可return self.checkTwoTree(root.left, root.right)。【此处一定要加return，否则得到的全是空值】

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
        return self.checkTwoTree(root.left, root.right)

    def checkTwoTree(self, leftTree, rightTree):
        if not leftTree and not rightTree:
            return True
        if not leftTree and rightTree:
            return False
        if leftTree and not rightTree:
            return False
        if leftTree.val != rightTree.val:
            return False
        left = self.checkTwoTree(leftTree.left, rightTree.right)
        right = self.checkTwoTree(leftTree.right, rightTree.left)
        return left and right
```