### 解题思路
很简单的思路，直接看代码

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


#bfs
class Solution:
    def pathSum(self, root: TreeNode, target: int) -> List[List[int]]:
        if not root: return list()
        res = list()
        path = [root.val]
        queue = [(root, target-root.val, path)]
        while queue:
            length = len(queue)
            for _ in range(length):
                node, val, pth = queue.pop(0)
                if val == 0:
                    if not node.left and not node.right:
                        res.append(pth)
                if node.left:
                    queue.append((node.left, val-node.left.val, pth+[node.left.val]))
                if node.right:
                    queue.append((node.right, val-node.right.val, pth+[node.right.val]))
        return res

# dfs
class Solution:
    def pathSum(self, root: TreeNode, target: int) -> List[List[int]]:
        res = list()
        if not root: return res
        def dfs(tree, val, path=list()):
            if not tree.left and not tree.right and val == tree.val:
                res.append(path+[tree.val])
                return
            elif not tree.left and not tree.right and val != tree.val:
                return
            if tree.left:
                dfs(tree.left, val-tree.val, path+[tree.val])
            if tree.right:
                dfs(tree.right, val-tree.val, path+[tree.val])
        dfs(root, target)
        return res
```