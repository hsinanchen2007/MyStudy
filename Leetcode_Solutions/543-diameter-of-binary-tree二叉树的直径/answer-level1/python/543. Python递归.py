### 解题思路
使用后序遍历，可以返回两个值，也可以定义一个递归函数外的局部变量，返回一个值。

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def diameterOfBinaryTree(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root is None:
            return 0
        def get_res(root):
            if root is None:
                return 0, 0
            left_tree_max, left_path_max = get_res(root.left)
            right_tree_max, right_path_max = get_res(root.right)
            # tree_max是当前子树包括的最大完整路径的节点数
            tree_max = max(left_path_max + right_path_max + 1, left_tree_max, right_tree_max)
            # path_max是当前子树能够提供的最大分支节点数
            path_max = max(left_path_max, right_path_max) + 1
            return tree_max, path_max
        return get_res(root)[0] - 1
```