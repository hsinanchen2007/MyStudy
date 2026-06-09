### 解题思路
要点:
1. 前序遍历二叉树,遍历根节点到其他节点的路径
2. 由于不要求一定从根节点开始,因此主函数需要递归每一个节点.
还是挺复杂的,怎么会是easy...

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def __init__(self):
        self.res = 0
    def pathSum(self, root, target):
        """
        :type root: TreeNode
        :type target: int
        :rtype: int
        """
        if not root:
            return 0
        self.get_path(root, target)
        self.pathSum(root.left, target)
        self.pathSum(root.right, target)
        return self.res

    def get_path(self, root, target):
        if not root:
            return
        if root.val == target:
            self.res += 1
        new_target = target - root.val
        self.get_path(root.left, new_target)
        self.get_path(root.right, new_target)

```