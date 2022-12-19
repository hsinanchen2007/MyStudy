### 解题思路
只需要将左右子树互换即可。

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
        def get_res(root):
            if root is None:
                return None
            left = get_res(root.left)
            right = get_res(root.right)
            root.left = right
            root.right = left
            return root
        return get_res(root)
```