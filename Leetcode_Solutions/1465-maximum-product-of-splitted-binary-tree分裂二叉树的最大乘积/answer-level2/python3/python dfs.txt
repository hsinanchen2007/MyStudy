dfs，在搜索过程中利用上次的结果求树的和，只需要重新加一次，时间复杂度是O(n)。bfs妥妥超时，不能利用储存结果，每次都要重新计算树和，时间复杂度约为O(n^2)。
```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
from queue import Queue

class Solution:
    def mysum(self, root: TreeNode) -> int:
        if root == None:
            return 0
        else :
            return root.val + self.mysum(root.left) + self.mysum(root.right)
    def dfs_find(self, root):
        if root:
            s = root.val
            s += self.dfs_find(root.left)
            s += self.dfs_find(root.right)
            if abs(s - int(self.tot/2)) < abs(self.re - int(self.tot/2)):
                self.re = s
            return s
        else:
            return 0
    def maxProduct(self, root: TreeNode) -> int:
        self.tot = self.mysum(root)
        self.re = self.tot

        
        self.dfs_find(root)
        return self.re * (self.tot - self.re) % (10**9 + 7)
            
```
