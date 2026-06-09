
```python []
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def balanceBST(self, root: TreeNode) -> TreeNode:
        if root is None:
            return root
        return self.sortedArrayToBST(self.get_node(root))

    def get_node(self,root):
        if root is None :
            return []
        return self.get_node(root.left)+[root.val] + self.get_node(root.right)
        

    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
        if not nums:
            return None
        mid = len(nums) // 2
        node = TreeNode(nums[mid])

        left = nums[:mid]
        right = nums[mid+1:]

        node.left = self.sortedArrayToBST(left)
        node.right = self.sortedArrayToBST(right)

        return node
```

