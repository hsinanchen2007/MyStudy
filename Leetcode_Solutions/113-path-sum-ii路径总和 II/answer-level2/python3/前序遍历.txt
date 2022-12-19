class Solution:
    def pathSum(self, root: TreeNode, Sum: int) -> List[List[int]]:
        stack = []
        res = []
        def core(p):
            if p:
                stack.append(p.val)
                if not p.left and not p.right and sum(stack) == Sum:
                    res.append(stack[:])
                core(p.left)
                core(p.right)
                stack.pop()
        core(root)
        return res