### 解题思路
1. 递归，递归的出口就是没有子节点的时候sum是否为0
2. 迭代

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def hasPathSum(self, root: TreeNode, sum: int) -> bool:
        # if not root:
        #     return False
        
        # sum -= root.val
        # if not root.right and not root.left:
        #     return sum == 0
        # return self.hasPathSum(root.right, sum) or self.hasPathSum(root.left, sum)

        if not root:
            return False
        
        de = [(root, sum-root.val)]
        while de:
            node, cur_val = de.pop()
            if not node.right and not node.left and cur_val == 0:
                return True
            if node.right:
                de.append((node.right, cur_val - node.right.val))
            if node.left:
                de.append((node.left, cur_val - node.left.val))
        return False

```