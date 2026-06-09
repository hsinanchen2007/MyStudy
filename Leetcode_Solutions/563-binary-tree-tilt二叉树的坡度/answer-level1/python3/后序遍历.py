![486b8a5b139466180380e60ed30a120.png](https://pic.leetcode-cn.com/62bb05feca78e91730ed7b8f9bff17fdcf3ab9c549172b99d81877a89fd94dae-486b8a5b139466180380e60ed30a120.png)

```python []
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findTilt(self, root: TreeNode) -> int:
        if not root:
            return 0
        global res
        res = 0
        def f(node):
            global res
            if node.left:
                f(node.left)
            if node.right:
                f(node.right)
            if not node.left:
                node.left_sum = 0
            else:
                node.left_sum = node.left.val + node.left.left_sum + node.left.right_sum
            if not node.right:
                node.right_sum = 0
            else:
                node.right_sum = node.right.val + node.right.left_sum + node.right.right_sum
            res += abs(node.left_sum - node.right_sum)
        f(root)
        return res

```

