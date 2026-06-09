```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def constructMaximumBinaryTree(self, nums: List[int]) -> TreeNode:
        # root is maximum number
        # stack  => indices
        # [2, 3, 1, 6]
        # Time complexity : O(N)
        # Space complexity: O(N) 
        if nums == []: return None # corner case
        stack = []
        for num in nums:
            node = TreeNode(num)
            tmp = None
            while stack and num > stack[-1].val:
                tmp = stack.pop()
            if tmp: node.left = tmp
            if stack != []:
                stack[-1].right = node
            stack.append(node)
        while len(stack) != 1:
            tmp = stack.pop()
            stack[-1].right = tmp
        return stack[-1]
```