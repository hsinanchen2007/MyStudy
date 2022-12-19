### 解题思路
设置一个变量flag，初始为true，当递归中发现左右子树的高度差大于1时，将变量改为false。

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
        if not root:
            return True
        self.flag = True

        def height(root):
            if not root:
                return 0
            l = height(root.left)
            r = height(root.right)
            if abs(l - r) > 1:
                self.flag = False
            return max(l, r) + 1

        height(root)
        return self.flag
```