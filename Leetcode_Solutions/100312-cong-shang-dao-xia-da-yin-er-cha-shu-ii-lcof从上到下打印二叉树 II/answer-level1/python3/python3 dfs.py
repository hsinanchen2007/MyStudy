### 解题思路
此处撰写解题思路

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        res = []
        def dfs(node,n):
            if not node: return
            if len(res)<n+1:
                res.append([])
            res[n].append(node.val)
            dfs(node.left,n+1)
            dfs(node.right,n+1)
        dfs(root,0)
        return res
```