### 解题思路
思路是dfs+递归，写一个递归函数返回它的子树所能达到的最大距离

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxAncestorDiff(self, root: TreeNode) -> int:
        #思路：递归
        def findmaxmin(node,min_,max_):
            if node == None:
                return max_ - min_
            if node.val > max_:
                max_ = node.val
            if node.val < min_:
                min_ = node.val
            left_distance = findmaxmin(node.left,min_,max_)
            right_distance = findmaxmin(node.right,min_,max_)
            return max(left_distance,right_distance)
        res = findmaxmin(root,min_ = root.val,max_ = root.val)
        return res

```