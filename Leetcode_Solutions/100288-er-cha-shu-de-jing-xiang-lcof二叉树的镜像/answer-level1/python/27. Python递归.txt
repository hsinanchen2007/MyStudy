### 解题思路
前序、中序、后序遍历都可以，交换左右两棵子树即可。

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def mirrorTree(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        def get_res(root):
            if root is None:
                return None
            left = get_res(root.right)
            right = get_res(root.left)
            root.left = left
            root.right = right
            return root
        return get_res(root)
```