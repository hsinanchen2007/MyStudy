```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def flipMatchVoyage(self, root: TreeNode, voyage: List[int]) -> List[int]:
        nodeOrder = {value: index for index, value in enumerate(voyage)}
        res = []
        # Time complexity: O(N)
        # Space complexity: O(N)
        def flipTree(node, res, preOrder): # try it's best to flip
            if node == None: return
            preOrder.append(node.val)
            if node.left and node.right:
                if nodeOrder[node.left.val] > nodeOrder[node.right.val]:
                    node.left, node.right = node.right, node.left
                    res.append(node.val)
            flipTree(node.left, res, preOrder)
            flipTree(node.right, res, preOrder)
        preOrder = []
        flipTree(root, res, preOrder)
        return res if preOrder == voyage else [-1]
```