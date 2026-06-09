class Solution:
    def sumNumbers(self, root: TreeNode) -> int:
        if not root:
            return 0
        stack = [(root, '')]
        res = []
        while stack:
            node, char = stack.pop()
            if not node.right and not node.left:
                res.append(char + str(node.val))
            if node.right:
                stack.append((node.right, char + str(node.val)))
            if node.left:
                stack.append((node.left, char + str(node.val)))
        return  sum([int(ch) for ch in res])