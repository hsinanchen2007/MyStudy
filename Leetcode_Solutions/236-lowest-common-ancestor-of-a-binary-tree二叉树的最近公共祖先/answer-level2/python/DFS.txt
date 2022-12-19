```
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def __init__(self):
       self.result = TreeNode(float("inf"))
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        : 思路： 深度优先，从叶节点开始判断当前分支是不是包含目标节点，包含则返回True，如果左右子分支都返回True或者当前节点是目标节点，且有一个分支返回True
        """

        def dfs(root):
            if not root:
                return False
            left_result = dfs(root.left)
            right_result = dfs(root.right)
            
            if root.val == p.val or root.val == q.val:  # 当前节点未目标节点
                if left_result or right_result:  # 左右分支有一个True
                    self.result = root
                return True
            if left_result and right_result:  # 左右分支都为True
                self.result = root
                return True
            if left_result or right_result:
                return True
               
        dfs(root)
        return self.result
```
