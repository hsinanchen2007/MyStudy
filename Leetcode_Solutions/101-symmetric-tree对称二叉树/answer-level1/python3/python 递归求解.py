1. 两颗树t1，t2镜像对称的条件是，根节点的值相等，同时t1的左子树与t2的右子树对称，并且t1的右子树与t2的左子树对称。
    这其实就是递归条件了
2. 那么递归的终止条件是什么呢？ 
    2.1 两个节点皆空，此时是空节点，返回True
    2.2 一个节点为空，另一个不为空，放回False
3. 还有一个问题，现在输入只有一颗数，我要咋递归比较两棵树呢？
    如果这棵树镜像对称，那么复制一棵，他两肯定镜像对称，这样t1，t2就有啦
```
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def Symmetric(self, p: TreeNode, q: TreeNode) -> bool:
        if not p and not q:
            return True
        if not p or not q:
            return False
        if p.val == q.val:
            return self.Symmetric(p.left, q.right) and self.Symmetric(p.right, q.left)
        else:
            return False

    def isSymmetric(self, root: TreeNode) -> bool:
        return self.Symmetric(root, root)
```
