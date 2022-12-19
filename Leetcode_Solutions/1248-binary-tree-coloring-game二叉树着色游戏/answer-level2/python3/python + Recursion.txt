```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def btreeGameWinningMove(self, root: TreeNode, n: int, x: int) -> bool:
        # n is odd
        # each node has a distinct value from 1 to n
        left_child_cnt = 0
        right_child_cnt = 0
        if n == 1: return False
        # Postorder traverse from bottom to top
        def count_nodes(node, x):
            nonlocal left_child_cnt, right_child_cnt
            if not node: return 0
            left_cnt = count_nodes(node.left, x)
            right_cnt = count_nodes(node.right, x)
            if node.val == x:
                left_child_cnt = left_cnt
                right_child_cnt = right_cnt
            return left_cnt + right_cnt + 1
        count_nodes(root, x)
        rest = n - left_child_cnt - right_child_cnt - 1
        a, b, c = sorted([rest, left_child_cnt, right_child_cnt])
        return c > a + b + 1
                
```