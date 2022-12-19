```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def verticalOrder(self, root: TreeNode) -> List[List[int]]:
        # bfs + hashtable
        if root == None: return []
        queue = collections.deque([[root, 0]])
        res = collections.defaultdict(list)
        while queue:
            top, index = queue.popleft()
            res[index].append(top.val)
            if top.left: 
                queue.append((top.left, index - 1))
            if top.right:
                queue.append((top.right, index + 1))
        res = sorted(res.items(), key = lambda x: x[0])
        return [val[1] for val in res]
```