### 解题思路
此处撰写解题思路
比较慢的代码
### 代码

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def delNodes(self, root: TreeNode, to_delete: List[int]) -> List[TreeNode]:
        res = [root]
        def dfs(node,val):
            if not node:
                return None
            if node.val == val:
                if node.left:
                    res.append(node.left)
                if node.right:
                    res.append(node.right)
                return None
            node.left = dfs(node.left,val)
            node.right = dfs(node.right,val)
            return node
        for d in to_delete:
            for n,i in enumerate(res):
                if dfs(i,d) == None:
                    res=res[:n]+res[n+1:]
        return res
            
```