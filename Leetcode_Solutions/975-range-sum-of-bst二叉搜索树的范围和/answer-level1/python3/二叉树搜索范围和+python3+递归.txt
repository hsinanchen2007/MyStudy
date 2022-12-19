执行用时 :268 ms, 在所有Python3提交中击败了98.49%的用户；内存消耗 :21.3 MB, 在所有Python3提交中击败了100.00%的用户

### 递归
跟其他用python的答案比较了一下，发现时间复杂度要好一点，主要是因为利用到了二叉搜索树的特性（代码中略有提及或者自行百度~），思路比较简单，就是递归。此外，题目应该是默认L<R。代码如下：
```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
# 若它的左子树不空，则左子树上所有结点的值均小于它的根结点的值； 
# 若它的右子树不空，则右子树上所有结点的值均大于它的根结点的值； 
# 它的左、右子树也分别为二叉排序树。
class Solution:
    def rangeSumBST(self, root: TreeNode, L: int, R: int) -> int:
        if not root:
            return 0
        else:
            if root.val>R:
                return self.rangeSumBST(root.left,L,R)
            elif root.val <L:
                return self.rangeSumBST(root.right,L,R)
            else:
                return root.val+self.rangeSumBST(root.left,L,R)+self.rangeSumBST(root.right,L,R)
```