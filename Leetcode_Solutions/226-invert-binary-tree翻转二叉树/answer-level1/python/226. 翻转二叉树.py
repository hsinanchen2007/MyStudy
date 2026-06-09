1. 递归
核心: 树
- Node节点
- left, right 子节点
我们只需要递归的将左右子节点交换, 直到节点为空或者是叶子节点

```
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
        if root != None:
            node = root
            node.left, node.right = self.invertTree(node.right), self.invertTree(node.left)
        else:
            return None

        return node
```
