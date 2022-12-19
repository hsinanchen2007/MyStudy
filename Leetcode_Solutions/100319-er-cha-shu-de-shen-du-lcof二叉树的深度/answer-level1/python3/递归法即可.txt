class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        count = 0
        if root:
            count += 1
            count += max(self.maxDepth(root.right),self.maxDepth(root.left))
        return count