### 解题思路
根据定义，检查每个Node是否满足子树深度差不大于1
- 定义depth函数用于返回树的深度
- isBalanced递归实现，返回 逻辑 （根结点满足？ and isBalanced(左子树根) and isBalanced(右子树根)）
- 递归终止条件：空节点满足条件平衡二叉树，return True

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isBalanced(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if root==None:
            return True
        #遍历二叉树，检查每一个节点是否符合
        return abs(self.depth(root.left)-self.depth(root.right))<=1 and self.isBalanced(root.left) and self.isBalanced(root.right)
    
    def depth(self,root):
        if root==None:
            return 0
        return 1+max(self.depth(root.left),self.depth(root.right))
    
```