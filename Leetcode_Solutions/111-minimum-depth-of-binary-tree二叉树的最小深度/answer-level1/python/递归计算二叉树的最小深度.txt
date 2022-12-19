### 解题思路
1.判断根节点是否存在，若不存在则返回0.
2.判断左右节点是否存在，存在则返回两者的最小值。
3.一个存在一个不存在，就返回存在的深度。


### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    #     """
    #     :type root: TreeNode
    #     :rtype: int
    #     """
    def minDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0
        elif root.left and root.right:
            return 1 + min(self.minDepth(root.left),self.minDepth(root.right))
        elif root.left:
            return 1 + self.minDepth(root.left)
        elif root.right:
            return 1 + self.minDepth(root.right)
        else:
            return 1
```