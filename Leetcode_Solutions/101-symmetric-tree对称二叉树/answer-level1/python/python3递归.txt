# 解题思路：
因为root是在对称轴上的，所以可以将其忽略，看成两颗树是否对称。

判断对称的条件是对于两棵树left和right，有以下条件才可判为对称：
1. 根节点值相等 or 都为None
2. 一棵树的左子树和另一棵树的右子树对称【P.s 树是递归定义的，在做相关题目时优先考虑递归做法】
3. 分别对子树进行递归

由题目图示可看出，若子树不满足对称，那么包含该子树的树一定不对称，由此产生递归做法。

代码如下：
```python []
class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        def isSy(left,right):
            if left==None and right==None:
                return True
            elif left!=None and right !=None and left.val==right.val:
                return isSy(left.left,right.right) & isSy(left.right,right.left)
            else:
                return False
        if root is None:
            return True
        return isSy(root.left,root.right)
```
