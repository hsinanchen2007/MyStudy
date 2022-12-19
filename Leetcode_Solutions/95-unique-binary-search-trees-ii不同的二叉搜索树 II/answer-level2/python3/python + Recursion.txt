```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def generateTrees(self, n: int) -> List[TreeNode]:
        # 3 => [1, 3], [None], [None, 3] [2, None]]
        if n == 0: return []
        def generate(l, r):
            if l > r: return [None]
            if l == r: return [TreeNode(l)]
            res = []
            for i in range(l, r + 1):
                left_list = generate(l, i - 1)
                right_list = generate(i + 1, r)
                for l_node in left_list:
                    for r_node in right_list:
                        node = TreeNode(i)
                        node.left = l_node
                        node.right = r_node
                        res.append(node)
            return res
        res = generate(1, n)
        return res
```