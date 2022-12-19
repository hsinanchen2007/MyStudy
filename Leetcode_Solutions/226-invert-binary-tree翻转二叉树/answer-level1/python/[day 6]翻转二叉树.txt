### 解题思路


套模版

void traverse(TreeNode root) {
    '''前序遍历'''
    traverse(root.left)
    '''中序遍历'''
    traverse(root.right)
    '''后序遍历'''
}


### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def invertTree(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        if not root:
            return root
        left = right = None
        if  root.left:
            left = self.invertTree(root.left)
        if  root.right:
            right = self.invertTree(root.right)

        root.left = right 
        root.right =  left
        return root
```