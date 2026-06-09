对于每个节点，返回以该节点为根的树中所有以不同方式组成的和。

时间复杂度：O(N)
空间复杂度：O(log(N))，即树的深度。完全非平衡二叉树下为O(N).

class Solution:
    def __init__(self):
        self.ans = 0

    def pathSum(self, root: TreeNode, sum: int) -> int:
        self.pathSumHelper(root, sum)
        return self.ans

    def pathSumHelper(self, root, sum):
        if not root:    return []
        left_sum_set = self.pathSumHelper(root.left, sum)
        right_sum_set = self.pathSumHelper(root.right, sum)
        curr_sum_set = [val+root.val for val in left_sum_set+right_sum_set] + [root.val]
        for val in curr_sum_set:
            if val == sum:  self.ans += 1
        return curr_sum_set