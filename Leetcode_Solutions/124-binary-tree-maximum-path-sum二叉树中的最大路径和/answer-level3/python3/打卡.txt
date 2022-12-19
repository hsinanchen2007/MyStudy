```
class Solution:
    def __init__(self):
        self.ans = None

    def maxPathSum(self, root: TreeNode) -> int:
        self.__recur(root)
        return self.ans

    def __recur(self, root):
        if not root:
            return 0
        else:
            left_gain = max(self.__recur(root.left), 0)
            right_gain = max(self.__recur(root.right), 0)

        res = root.val + max(left_gain, right_gain, 0)
        node_sum = root.val + left_gain + right_gain

        if not self.ans:
            self.ans = node_sum
        elif node_sum > self.ans:
            self.ans = node_sum
        return res









```
