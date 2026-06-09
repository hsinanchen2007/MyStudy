### 解题思路
递归到叶子节点保存
### 代码
```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def leafSimilar(self, root1: TreeNode, root2: TreeNode) -> bool:
        res1,res2=[],[]
        def dfs(root,res):
            if not root.left and not root.right:
                res.append(root.val)
                return res
            if root.left:
                dfs(root.left,res)
            if root.right:
                dfs(root.right,res)
            return res
        return dfs(root1,[])== dfs(root2,[])
```

