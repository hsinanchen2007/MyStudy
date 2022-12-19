```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def printTree(self, root: TreeNode) -> List[List[str]]:
        # row == height of the tree
        # column should always be odd
        # root in the middle
        def get_height(node):
            if not node: return 0
            return max(get_height(node.left), get_height(node.right)) + 1

        def fill_val(node, l, r, res, layer):
            if node == None: return
            mid = (l + r) // 2
            res[layer][mid] = str(node.val)
            fill_val(node.left, l, mid, res, layer + 1)
            fill_val(node.right, mid + 1, r, res, layer + 1)

        height = get_height(root)
        width = 2 ** height - 1
        if width % 2 == 0: width += 1
        res = [[""] * width for _ in range(height)]
        fill_val(root, 0, width, res, 0)
        return res
```