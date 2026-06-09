### 解题思路
注释帮助理解代码
DFS遍历的核心就是找到递归终止条件并理解终止条件的意思

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        if root==None or root==p or root==q:
            return root
        left=self.lowestCommonAncestor(root.left,p,q)
        right=self.lowestCommonAncestor(root.right,p,q)
        if not left:
            return right #左子树没有p/q中任一节点，而右子树找到了节点等于p或q的根节点，则该根节点肯定就是公共祖先
        if not right:
            return left #右子树没有p/q中任一节点，而左子树找到了节点等于p或q的根节点，则该根节点肯定就是公共祖先
        else:
            return root #p、q分别在左子树和右子树中找到，则公共祖先肯定是根节点
```