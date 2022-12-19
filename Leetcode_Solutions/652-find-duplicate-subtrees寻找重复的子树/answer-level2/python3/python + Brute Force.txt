```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findDuplicateSubtrees(self, root: TreeNode) -> List[TreeNode]:
        res = []
        visited = collections.defaultdict(int)
        def getSubTreeNodes(node):
            if node == None: return '#'
            tree_str = getSubTreeNodes(node.left)  + getSubTreeNodes(node.right) + str(node.val)
            visited[tree_str] += 1
            if visited[tree_str] == 2: res.append(node)
            return tree_str
        getSubTreeNodes(root)
        return res
```