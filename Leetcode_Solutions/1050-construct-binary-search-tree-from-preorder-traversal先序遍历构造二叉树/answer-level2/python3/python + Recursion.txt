```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# [8, 5, 1, 7, 10, 12]
# [1, 5, 7, 8, 10, 12]
class Solution:
    def bstFromPreorder(self, preorder: List[int]) -> TreeNode:
        # corner case preorder == []
        # Time complexity: O(NlogN)
        # Space complexity: O(N)
        inorder = sorted(preorder)
        index_dict = collections.defaultdict(int)
        for i, val in enumerate(inorder):
            index_dict[val] = i
        def create_tree(preL, preR, inL, inR):
            if preL > preR: return None
            val = preorder[preL]
            k = index_dict[val] - inL
            node = TreeNode(val)
            node.left = create_tree(preL + 1, preL + k, inL, inL + k - 1)
            node.right = create_tree(preL + k + 1, preR, inL + k + 1, inR)
            return node
        root = create_tree(0, len(preorder) - 1, 0, len(inorder) - 1)
        return root
```