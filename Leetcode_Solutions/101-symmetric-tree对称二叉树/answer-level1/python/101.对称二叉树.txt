### 解题思路
- 空树对称
- 非空树若对称，则左子树与右子树对称
- 定义函数判断**两颗树**是否对称：
- 若两树根均为空，对称！
- 仅有一个为空，不对称！
- 两个都不对称，则树根节点需要值相同 and 左子树的左子树的与右子树的右子树对称，左子树的右子树与右子树的左子树对称（递归）


### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if not root:
            return True
        return self.mirror_tree(root.left,root.right)
    
    def mirror_tree(self,left,right):
        if left==None and right==None:return True
        if (left==None and right!=None)or(left!=None and right==None):return False
        return left.val==right.val and self.mirror_tree(left.left,right.right) and self.mirror_tree(left.right,right.left)
```