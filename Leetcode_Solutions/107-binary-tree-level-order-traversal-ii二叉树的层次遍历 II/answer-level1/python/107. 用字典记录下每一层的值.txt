### 解题思路
使用一个字典，字典的key即为层数，字典的value则是用来记录该层的每一值的list。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return []
        
        res = {}
        def __dfs(node, iteration):
            if iteration in res:
                res[iteration].append(node.val)
            else:
                res[iteration] = [node.val]
            
            if node.left:
                __dfs(node.left, iteration+1)
            if node.right:
                __dfs(node.right, iteration+1)
            return res
        
        traversal = __dfs(root, 1)

        return [traversal[item] for item in sorted(traversal.keys(), reverse=True)]
        
```