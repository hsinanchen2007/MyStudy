class Solution(object):
    def postorder(self, root):
        """
        :type root: Node
        :rtype: List[int]
        """
        ans = []
        if root ==None:
            return ans
        for child in root.children:
            ans = ans + self.postorder(child)
        ans= ans + [root.val]
        return ans