class Solution(object):
    def postorder(self, root):
        """
        :type root: Node
        :rtype: List[int]
        """
        # ans = []
        # if root ==None:
        #     return ans
        # for child in root.children:
        #     ans = ans + self.postorder(child)
        # ans= ans + [root.val]
        # return ans
        res, stack = [], []
        if not root:
            return res
        stack.insert(0, root)
        while len(stack) > 0:
            node = stack.pop(0)
            res.insert(0, node.val)
            for child in node.children:
                stack.insert(0, child)
        return res
