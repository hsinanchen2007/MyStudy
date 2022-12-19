```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def generateTrees(self, n: int) -> List[TreeNode]:
        if n == 0: return []
        def generate_subTrees(s, e):
            if s > e: return [None]
            if s == e:  return [TreeNode(s)]
            res = []
            for i in range(s, e + 1): 
                for left in generate_subTrees(s, i - 1):
                    for right in generate_subTrees(i + 1, e): 
                        node = TreeNode(i)
                        node.left = left
                        node.right = right
                        res.append(node)
            return res
        return generate_subTrees(1, n)
```