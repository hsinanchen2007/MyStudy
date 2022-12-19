### 解题思路
本题为**二叉树和递归**结合的基础题
    1. 首先给程序一个出口，当树节点为空时返回长度0
    2. 然后递归地求解左右子树的最大深度
    3. 最后返回两者中最大的深度加上根节点的1长度即为当前树的最大深度

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        def helper(root):
            if not root:
                return 0
            left=helper(root.left)
            right=helper(root.right)
            return max(left,right)+1
        return helper(root)
```