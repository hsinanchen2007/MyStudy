
class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if not root:
            return 0
        self.maxdepth = 0
        def helper(node, depth):
            self.maxdepth = max(depth, self.maxdepth) 
            if not node:
                return self.maxdepth
            if node.left:
                helper(node.left, depth+1)
            if node.right:
                helper(node.right, depth+1)
        helper(root, 1)
        return self.maxdepth