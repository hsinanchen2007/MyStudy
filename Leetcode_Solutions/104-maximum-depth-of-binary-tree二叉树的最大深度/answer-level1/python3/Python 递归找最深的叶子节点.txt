### 解题思路
递归找最深的叶子节点用count记录

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
        def DFS(root,count,maxcount):
            if root:
                if(root.left):
                    DFS(root.left,count+1,maxcount)
                if(root.right):
                    DFS(root.right,count+1,maxcount)
                maxcount[0] = max(count,maxcount[0])
            else:
                return
        
        count = 1 
        maxcount = [0]
        if not root:
            return 0
        DFS(root,count,maxcount)
        return maxcount[0]
```