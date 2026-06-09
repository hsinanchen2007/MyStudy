### 解题思路
    max_(root) 是只能直线向下走，不能带有折点的最大路径
    max_(root) = {
        root.val, 
        root.val + max_(root.right)
        root.val + max_(root.left)
    }
    max(root) 是要求解的最大路径
    max(root) = {
        max(root.left), 
        max(root.right), 
        root.val + max_(root.right) + max_(root.left), 
        max_(root)
    }
    再处理一下边界条件，就可以了

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def maxPathSumNew(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0, 0
        if not root.left and not root.right:
            return root.val, root.val

        max_ = root.val
        if root.right:
            max_right, max_right_new = self.maxPathSumNew(root.right)
            max_ = max(max_, root.val+max_right_new)
        if root.left:
            max_left, max_left_new = self.maxPathSumNew(root.left)
            max_ = max(max_, root.val+max_left_new)

        if not root.left and root.right:
            return max(max_right, max_), max_
        if not root.right and root.left:
            return max(max_left, max_), max_
        return max(max_left, max_right, max_, max_left_new + max_right_new + root.val), max_
    def maxPathSum(self, root):
        return self.maxPathSumNew(root)[0]

```