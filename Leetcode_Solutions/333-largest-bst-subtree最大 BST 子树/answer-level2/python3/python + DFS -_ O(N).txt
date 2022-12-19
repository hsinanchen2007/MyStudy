```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def largestBSTSubtree(self, root: TreeNode) -> int:
        # find the largest subtree
        # BST: binary search tree
        # largest node contain in it

        # post order traverse
        # Time complexity: O(N)
        # Space complexity: O(1)
        
        max_cnt, res = 1, root
        def solve(node, val):
            nonlocal max_cnt, res
            if not node: return (True, val, val, 0)
            l_flag, l_min, l_max, l_cnt = solve(node.left, node.val)
            r_flag, r_min, r_max, r_cnt = solve(node.right, node.val)
            if not node.left:
                l_min = node.val
                l_max = node.val - 1
            if not node.right:
                r_max = node.val
                r_min = node.val + 1
            if l_flag and r_flag and l_max < node.val < r_min:
                cnt = l_cnt + r_cnt + 1
                if cnt > max_cnt:
                    max_cnt = cnt
                    res = node
                return (True, l_min, r_max, cnt)
            else: return (False, 0, 0, 0)
        if not root: return 0
        solve(root,root.val)
        return max_cnt            
```