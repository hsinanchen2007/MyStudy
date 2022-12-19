### 解题思路
# 如果有左右子树，两种情况 ：
* 如果是连续递增就更新一下最长路径
* 如果不是连续递增就重置当前的路径长度


### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def longestConsecutive(self, root: TreeNode) -> int:
        self.res = 0
        if not root:
            return 0
        def help(root,cur):
            if not root:
                return 
            if not root.right and not root.left:
                self.res = max(self.res,cur)
            if root.right:
                if root.right.val == root.val+1:
                    help(root.right,cur+1)
                    self.res = max(self.res,cur+1)
                else:
                    help(root.right,1)
            if root.left:
                if root.left.val == root.val+1:
                    help(root.left,cur+1)
                    self.res = max(self.res,cur+1)
                else:
                    help(root.left,1)
            
        help(root,1)        
        return self.res

        
```