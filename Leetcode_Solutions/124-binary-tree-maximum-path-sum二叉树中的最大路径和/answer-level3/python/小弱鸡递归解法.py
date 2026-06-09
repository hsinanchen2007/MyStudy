### 解题思路
基本思路就是用一个递归，递归每次的返回值是某个节点所延申的一条路径的最大值
### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxPathSum(self, root: TreeNode) -> int:
        self.max_path = root.val
        def helper(node):
            if node==None:
                return 0
            else:
                x = node.val
                l = helper(node.left)
                r = helper(node.right)
                self.max_path = max(self.max_path,x,x+l,x+r,x+l+r)
                return max(x,x+l,x+r)
        helper(root)
        return self.max_path
            
```