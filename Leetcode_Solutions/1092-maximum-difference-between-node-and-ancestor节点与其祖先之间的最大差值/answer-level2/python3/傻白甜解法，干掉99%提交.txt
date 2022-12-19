执行用时 :
48 ms
, 在所有 Python3 提交中击败了
99.07%
的用户
内存消耗 :
20 MB
, 在所有 Python3 提交中击败了
100.00%
的用户
```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxAncestorDiff(self, root: TreeNode) -> int:
        self.res = 0
        
        self.solve(root, root.val, root.val)
        return self.res
    
    
    def solve(self, node, max_ans, min_ans):
        val = node.val
        a = abs(max_ans-val)
        b = abs(min_ans-val)
        self.res = max([self.res,a,b])
        if max_ans<val:
            max_ans = val
        if min_ans>val:
            min_ans = val
        
        if node.left:
            self.solve(node.left, max_ans, min_ans)
        
        if node.right:
            self.solve(node.right, max_ans, min_ans)
        
```
