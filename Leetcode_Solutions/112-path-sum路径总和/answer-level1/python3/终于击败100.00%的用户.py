### 解题思路
递归进行遍历节点
每次遍历减去当前节点的值，
直到是叶子节点判断sum的值是不是等于0就可以了

### 代码
![739870203.png](https://pic.leetcode-cn.com/7171995bf32e1ab89c5b538ce04f3b5e9fccc7aaded1580cc5529988e12c3a62-739870203.png)

```python3
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def hasPathSum(self, root: TreeNode, sum: int) -> bool:
        """
            给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，
            这条路径上所有节点值相加等于目标和。
            思路：
            1.把所有的路径全部记录，然后去判断有没有这种。
                改进：不查全部，而是只要查到有一条就返回True，找完还是没有就返回False
        :param root:
        :param sum:
        :return:
        """
        if root:
            if not root.left and not root.right:
                return root.val == sum
            elif not root.left:
                return self.hasPathSum(root.right, sum - root.val)
            elif not root.right:
                return self.hasPathSum(root.left, sum - root.val)
            else:
                return self.hasPathSum(root.left, sum - root.val) or self.hasPathSum(root.right, sum - root.val)
        else:
            return False

```