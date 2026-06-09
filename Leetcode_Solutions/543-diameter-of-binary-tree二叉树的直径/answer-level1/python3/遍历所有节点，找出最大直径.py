class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        self.d = 0
        def depth(root):
            if not root:
                return 0
            left = depth(root.left)
            right = depth(root.right)
            self.d = max(self.d, left+right)
            return max(left, right)+1
        depth(root)
        return self.d

思路：此题不单是求二叉树最大深度-2，而是要求所有子节点的最大深度-2。因此在计算二叉树最大深度的基础上，维护一个self.d，保存每一个子节点的最大直径。