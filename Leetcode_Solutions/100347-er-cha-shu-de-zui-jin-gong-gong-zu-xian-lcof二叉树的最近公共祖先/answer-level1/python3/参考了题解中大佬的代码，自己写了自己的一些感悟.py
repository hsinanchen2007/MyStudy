### 解题思路
### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root, p, q):
        """跟二叉树的坡度一题有异曲同工之妙，边遍历边出结果"""

        """
        首先，公共节点要么在左子树里面，要么在右子树里面，要么在根节点处
        其次，如果左子树里面有一个点，则左子树就返回这个点，同理右子树有另一个点，就返回这个点，如果左子树或者右子树一个点都没有，就返回空
        最后，
        如果左子树返回是空，说明根节点不是最近的公共祖先，那么最近的公共祖先结果就在右子树里面，
        同理，如果右子树返回为空，说明根节点不是最近的公共祖先，说明最近公共祖先在左子树里面，
        如果左右子树一边返回了一个节点，即左右都不是空，则说明根节点就是最近的公共祖先了
        """

        """反思，跟坡度一样，只不过这里遍历左右子树之后返回的是找到的哪个节点，或者没找到节点，而坡度一题返回的是左右子树的节点之和"""
        if root==None or root==p or root==q:   #递归终止条件，如果找到一个节点
            return root
        left=self.lowestCommonAncestor(root.left,p,q)     #遍历左子树
        right=self.lowestCommonAncestor(root.right,p,q)   #遍历右子树
        if not left:  
            return right
        if not right:
            return left
        return root
```