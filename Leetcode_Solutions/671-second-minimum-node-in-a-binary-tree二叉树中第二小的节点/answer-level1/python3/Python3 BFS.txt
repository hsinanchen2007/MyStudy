### 解题思路
直觉: BFS/DFS找到所有第一次比根节点大的,取min

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findSecondMinimumValue(self, root: TreeNode) -> int:
        #直觉: BFS/DFS找到所有第一次比根节点大的,取min:
        #BFS Done
        
        res = []
        queue = [root]
        while queue:
            node = queue.pop(0)
            if not node:
                continue
            
            if node.val == root.val:
                queue.append(node.left)
                queue.append(node.right)
            else:
                res.append(node.val)
    
        return -1 if not res else min(res)

```