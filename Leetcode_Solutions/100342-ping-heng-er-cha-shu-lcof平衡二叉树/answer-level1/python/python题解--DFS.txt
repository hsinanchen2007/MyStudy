### 解题思路
![image.png](https://pic.leetcode-cn.com/643ff85a50abd191ca9711c3644ad5fa71acb03688ebeb7fe9d52e79da8a8ce4-image.png)
- 思路很明确,设置一个全局变量`result = [0]`,直接进行DFS遍历,遇到不符合条件的即,左右子树的深度只差大于的就让`result[0] = 1`,再返回左右子树中深度大的那一个

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
        result = [0]
        def dfs(root):
            if not root:
                return 0
            left_depth = dfs(root.left)
            right_depth = dfs(root.right)
            if abs(left_depth - right_depth) > 1:
                result[0] = 1        
            return max(left_depth + 1, right_depth + 1)
        dfs(root)
        return (not result[0])






```