

思路：二叉树的对称不是左子树等于右子树，而是左子树的左子树==右子树的右子树and左子树的右子树==右子树的左子树
采用递归即可

因为要判断的是左子树和右子树的子节点，所以要传入的是两个节点进行对比，需要另外一个check函数来进行判断


```
class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        if not root:
            return True
        return self.check(root.left, root.right)
    
    def check(self, left, right):
        # 同时为空说明比较完毕，那么为True
        if not left and not right:
            return True
        # 如果只有一个为空，或者两个节点的值不相等，则为False
        if not left or not right or (left.val != right.val):
            return False
        # 递归判断左子树的左子树?=右子树的右子树and左子树的右子树?=右子树的左子树
        return self.check(left.left, right.right) and self.check(left.right, right.left)
```
