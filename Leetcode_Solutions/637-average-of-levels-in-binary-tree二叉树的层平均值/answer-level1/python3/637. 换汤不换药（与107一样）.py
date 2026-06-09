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
    def averageOfLevels(self, root: TreeNode) -> List[float]:
        if not root:
            return None
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

        return [sum(traversal[item])/len(traversal[item]) for item in sorted(traversal.keys(), reverse=False)]     

```