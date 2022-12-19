### 解题思路
root = TreeNode(preorder[0])
root.left = self.buildTree(）
root.right = self.buildTree(）
return root

preorder 中的第一个元素一定是树的根，这个根又将 inorder 序列分成了左右两棵子树。
构建二叉树的问题本质上就是：
    找到各个子树的根节点 root
    构建该根节点的左子树
    构建该根节点的右子树
整个过程我们可以用递归来完成。


### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """

        if len(inorder)==0:
            return None
        
        root = TreeNode(preorder[0])
        mid = inorder.index(preorder[0])
        root.left = self.buildTree(preorder[1:mid+1], inorder[:mid])
        root.right = self.buildTree(preorder[mid+1:], inorder[mid+1:])

        return root
```